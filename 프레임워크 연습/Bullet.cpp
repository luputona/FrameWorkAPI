#include "StdAfx.h"
#include "Bullet.h"
#include "DirectionalShooter.h"
#include "Obj.h"
#include "ObjFactory.h"
#include "EnSpiral.h"
#include "Player.h"

//list<string,CObj*>* CBullet::m_pBulletList = NULL;

CBullet::CBullet(void) :
m_fBulletSpeed(0.0f),
m_fAngleRate(0.0f),
m_fSpeedRate(0.0f),
m_nCount(0),
m_nInterval(0),
m_nTime(0),
m_fCX(0.0f),
m_fCY(0.0f)
{
	
}

void CBullet::Initialize()
{
	
	m_tInfo.fCX = 53;
	m_tInfo.fCY = 12;

	m_strBulletID = "DIRECTIONAL";
	//m_fSpeed = 10;
/*
	m_fBulletAngle = 0.0f;
	m_fAngleRate = 0.0f;

	m_fSpeedRate = 0.5f;
	m_fBulletSpeed = 0.0001f;

	

	m_dwTime = GetTickCount();

	m_nInterval = 10;
	m_nCount = 1;
	m_nTime = 0;*/

}

CBullet::~CBullet(void)
{
	Release();
}


//void CBullet::MoveBullet()
//{		
//
//	//m_tInfo.fX += cosf(m_fAngle * PI /180)* m_fSpeed;
//	//m_tInfo.fY += -sinf(m_fAngle * PI / 180) * m_fSpeed;
//
//	//각도를 라디안 단위로 변환
//	float fRad = m_fBulletAngle * PI * 2; //탄의 각ㄱ도와 속도를 사용 탄의 좌표를 갱신
//
//	//각도와 속도를 사용해서 좌표 갱신
//	m_tInfo.fX += m_fBulletSpeed * cosf(fRad);
//	m_tInfo.fY += m_fBulletSpeed * -sinf(fRad);
//
//	if (m_nTime == 0)
//	{
//		for (int i = 0; i<m_nCount; i++)
//		{
//			m_fBulletAngle = m_fAngle + (float)i/m_nCount;
//			m_fBulletAngle += m_fAngleRate;
//			//m_fSpeed += m_fSpeed;
//			m_fSpeedRate += m_fSpeedRate;
//		}
//		
//		//m_fBulletAngle -= floor(m_fBulletAngle);
//		m_fBulletSpeed += m_fSpeedRate;
//	}
//	m_nTime = (m_nTime+1)%m_nInterval;
//
//
//	//m_fAngle += m_fAngleRate;
//
//	//각도에 각속도 계산
//	//m_fBulletAngle += m_fAngleRate;
//
//	//속도에 가속도 가산
//	//m_fSpeed += m_fSpeedRate;	
//}

void CBullet::MoveBullet()
{
	//기본 탄환
	//탄의 각ㄱ도와 속도를 사용 탄의 좌표를 갱신
	//float fRad = m_fAngle * PI * 2; 

	//각도와 속도를 사용해서 좌표 갱신
	//m_tInfo.fX += m_fSpeed * cosf(fRad);
	//m_tInfo.fY += m_fSpeed * -sinf(fRad);

	m_tInfo.fX += cosf(m_fAngle * PI /180) * m_fSpeed;
	m_tInfo.fY += -sinf(m_fAngle * PI / 180) * m_fSpeed;


	if (m_dwTime + 50 < GetTickCount())
	{
		m_dwTime = GetTickCount();

		//각도를 라디안 단위로 변환


		//각도에 각속도 계산
		m_fAngle += m_fAngleRate;

		

		//속도에 가속도 가산
		m_fSpeed += m_fSpeedRate;
	}
}


int CBullet::Progress()
{	
	//MoveBullet();
	//TestPart();
	
	//m_cDirShooter->BulletMove();
	
/*
	//기본 탄환

	//각도를 라디안 단위로 변환
	float fRad = m_fAngle * PI * 2; //탄의 각ㄱ도와 속도를 사용 탄의 좌표를 갱신

	//각도와 속도를 사용해서 좌표 갱신
	m_tInfo.fX += m_fSpeed * cosf(fRad);
	m_tInfo.fY += m_fSpeed * sinf(fRad);

	//각도에 각속도 계산
	m_fAngle += m_fAngleRate;

	//속도에 가속도 가산
	m_fSpeed += m_fSpeedRate;

	//화면에서 탄이 나가면 삭제
	/*if (abs(m_fX) >= WINCX + m_tShape->fSize || abs(m_fY) >= WINCY + m_tShape->fSize )
	{
	m_bAlive = false;
	}*/


	return 0;	
}



void CBullet::Release()
{

}

void CBullet::Render( HDC hdc )
{	
	/*TransparentBlt(hdc,
	int(m_tInfo.fX - m_tInfo.fCX /2 ) + 40.f,
	int(m_tInfo.fY - m_tInfo.fCY /2 ),
	(int)m_tInfo.fCX, (int)m_tInfo.fCY,
	(*m_pMapBmp)[m_strBulletID]->GetMemDC(),
	0,0,
	(int)m_tInfo.fCX, (int)m_tInfo.fCY,RGB(255,0,216));*/
}

void CBullet::TestPart()
{
	m_fAngle += 5;
	CObj* pBullet = CObjFactory<CEnSpiral>::CreateEnSpiral(m_tInfo.fX +20 ,m_tInfo.fY, m_fAngle,10.f,10.f,0.0f);
	//CObj* pBullet = CObjFactory<CBullet>::CreateBullet(m_tInfo.fX ,m_tInfo.fY,m_fAngle);	
	m_pBulletList->push_back(pBullet);
}

