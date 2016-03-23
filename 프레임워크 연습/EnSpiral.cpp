#include "StdAfx.h"
#include "EnSpiral.h"

#include "Player.h"
#include "Obj.h"
#include "ObjFactory.h"
#include "CircleCol.h"

class CPlayer;
CEnSpiral::CEnSpiral(void)
{
}


CEnSpiral::~CEnSpiral(void)
{
	Release();
}

void CEnSpiral::Initialize()
{
	m_tInfo.fCX = 15;
	m_tInfo.fCY = 14;

	//m_tInfo.fCX = 53;
	//m_tInfo.fCY = 12;
	m_fAngle = 0.0f;
	m_fAngleRate = 0.0f;

	//m_fSpeedRate = 0.0f;
	//m_fSpeed = 10.1f;

	m_strBulletID = "Enemy_SPIRAL";

	m_dwTime = GetTickCount();
	m_dwBulletTime = GetTickCount();

	m_nInterval = 10;
	m_nCount = 1;
	m_nTime = 0;

	

}



int CEnSpiral::Progress()
{
	test();
	if (m_tInfo.fX > 810 || m_tInfo.fX < -10)
	{
		delete this;
		return 1;
	}
	else if (m_tInfo.fY < -10 || m_tInfo.fY > 610)
	{
		delete this;
		return 1;
	}

	if (CCircleCol::CircleCollision(this, m_eAttDir))
	{
		delete this;
		return 1;
	}



	//float fVecX = m_pPlayer->GetPosX() - m_tInfo.fX;
	//float fVecY = m_pPlayer->GetPosY() - m_tInfo.fY;

	//float fLength = sqrt(fVecX * fVecX + fVecY * fVecY);

	//float fSum = ( m_pPlayer->GetInfo().fCX /2 ) + (m_tInfo.fCX /2); //반지름 + 반지름 

	//if (fLength < fSum ) //반지름끼리 합이 더 크면 충돌
	//{
	//	/*if ( _eIdType == OBJ_PLAYER)
	//	{
	//	Safe_Delete(*iter);
	//	pObjList->erase(iter);
	//	}*/
	//	delete this;
	//	return 1;
	//}



	return 0;
}

void CEnSpiral::Render(HDC hdc)
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2 ),
		int(m_tInfo.fY - m_tInfo.fCY /2 ),
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strBulletID]->GetMemDC(),
		0,0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,RGB(255,0,216));
}

void CEnSpiral::Release()
{
	
}

void CEnSpiral::test()
{
	
	fRad = m_fAngle * PI / 180  ; 
	////각도와 속도를 사용해서 좌표 갱신
	
	//if (m_dwTime + 10 < GetTickCount())
	//{
		//m_dwTime = GetTickCount();
		//m_tInfo.fX += cosf(m_fAngle * PI /180 ) * m_fSpeed;
		//m_tInfo.fY += -sinf(m_fAngle * PI / 180 ) * m_fSpeed;
		m_tInfo.fX += m_fSpeed * cosf(fRad) + m_fAngleRate;
		m_tInfo.fY += m_fSpeed * -sinf(fRad)+ m_fAngleRate;

		//m_fAngle += m_fAngleRate;

		m_fSpeed += m_fSpeedRate;
	//}
}


void CEnSpiral::SpiralBullet(float* _fx, float* _fy, float* _fAngle, float* _fAngleRate, float* _fSpeed, float* _fSpeedRate)
{
	////기본 탄환
	////탄의 각ㄱ도와 속도를 사용 탄의 좌표를 갱신
	//fRad = *_fAngle * PI * 2; 
	////각도와 속도를 사용해서 좌표 갱신
	//*_fx += *_fSpeed * cosf(fRad);
	//*_fy += *_fSpeed * -sinf(fRad);

	m_tInfo.fX += cosf(*_fAngle * PI /180 ) * *_fSpeed;
	m_tInfo.fY += -sinf(*_fAngle * PI / 180) * *_fSpeed;

	if (m_dwTime + 50 < GetTickCount())
	{
		m_dwTime = GetTickCount();

		//각도를 라디안 단위로 변환
		

		//각도에 각속도 계산
		*_fAngle += *_fAngleRate;
		

		//속도에 가속도 가산
		*_fSpeed += *_fSpeedRate;
	}

/*
	//기본 탄환
	//탄의 각ㄱ도와 속도를 사용 탄의 좌표를 갱신
	fRad = m_fBulletAngle * PI * 2; 
	//각도와 속도를 사용해서 좌표 갱신
	m_tInfo.fX += m_fBulletSpeed * cosf(fRad);
	m_tInfo.fY += m_fBulletSpeed * -sinf(fRad);

	if (m_dwTime + 50 < GetTickCount())
	{
		m_dwTime = GetTickCount();

		//각도를 라디안 단위로 변환
		

		//각도에 각속도 계산
		m_fBulletAngle += m_fAngleRate;

		m_fBulletAngle -= floor(m_fBulletAngle);

		//속도에 가속도 가산
		//m_fBulletSpeed += m_fSpeedRate;
	}
*/
}

int CEnSpiral::TestCol(CObj* _pDst, CObj* _pSrc )
{
	float fVecX = _pDst->GetInfo().fX - _pSrc->GetInfo().fY;
	float fVecY = _pDst->GetInfo().fY - _pSrc->GetInfo().fY;

	float fLength = sqrt(fVecX * fVecX + fVecY * fVecY);

	float fSum = ( _pDst->GetInfo().fCX /2 ) + (_pSrc->GetInfo().fCX /2); //반지름 + 반지름 

	if (fLength < fSum ) //반지름끼리 합이 더 크면 충돌
	{
		/*if ( _eIdType == OBJ_PLAYER)
		{
		Safe_Delete(*iter);
		pObjList->erase(iter);
		}*/

		return 1;
	}


}
