#include "StdAfx.h"
#include "RensouhouZako.h"
#include "ObjFactory.h"
#include "DirectionalShooter.h"
#include "Bullet.h"
#include "Obj.h"
#include "EnDirShooter.h"
#include "CreateMgr.h"
#include "ObjMgr.h"
#include "EnSpiral.h"
#include "Player.h"
#include "CircleCol.h"

CRensouhouZako::CRensouhouZako(void) : 
//m_cCreateMgr(NULL),
m_Enemy(NULL)
{
}


CRensouhouZako::~CRensouhouZako(void)
{
	Release();

}

void CRensouhouZako::Initialize()
{

	//m_tInfo = INFO(2400,150,30,50);

	
	m_tInfo.fCX = 30;
	m_tInfo.fCY = 50;

	//m_fAngle = -0.77f;
	//m_fAngleRate = 0.00f;

	//m_fSpeed = 8.0f;
	//m_fSpeedRate = 0.115f;
	
	m_strEnemyID = "RensouhouZako1";


	m_dwDefault = GetTickCount();
	m_dwTime = GetTickCount();

	m_dwCreateTime = 180;
	m_dwTickTime = 100;
	m_nNumber = 1;

	m_dwDelayTime  = 60;


}

void CRensouhouZako::Move(float* _fx, float* _fy, float* _fAngle, float* _fAngleRate,  float* _fSpeed, float* _fSpeedRate, float* _fMovePosX, float* _fMovePosY,float* _fMoveEndPosY)
{
	//각도를 라디안 단위로 변환
	m_fRad = (*_fAngle) * PI * 2;

	(*_fx )-= (*_fSpeed);

	if ( m_dwTime + 107 < GetTickCount())
	{
		m_dwTime = GetTickCount();

		(*_fSpeed) -= (*_fSpeedRate);

		if (((*_fx) <= (*_fMovePosX) && (*_fy) >= (*_fMovePosY) ) && ((*_fx) <= (*_fMovePosX) && (*_fy) <= (*_fMoveEndPosY)) )
		{			
			BulletPattern();			
		}
		if ((*_fSpeed) == 0 )
		{
			(*_fSpeed) += (*_fSpeedRate);//속도에 가속도 가산
		}
	}	
	if (  *_fSpeed <0 )
	{
		(*_fx) += (*_fSpeed) * cosf(m_fRad);
		(*_fy) += (*_fSpeed) * -sinf(m_fRad);//각도와 속도를 사용해서 좌표 갱신	

		(*_fSpeedRate) += 0.04f;
		(*_fAngle) += (*_fAngleRate); //각도에 각속도 계산
		return;
	}
}


void CRensouhouZako::Render(HDC hdc)
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2 ),
		int(m_tInfo.fY - m_tInfo.fCY /2 ),
		(int)m_tInfo.fCY, (int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strEnemyID]->GetMemDC(),
		0,0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,RGB(255,255,255));


}

void CRensouhouZako::Release()
{

}

int CRensouhouZako::Progress()
{
	Move(&m_tInfo.fX, &m_tInfo.fY, &m_fAngle, &m_fAngleRate, &m_fSpeed, &m_fSpeedRate, &m_fMovePosX, &m_fMovePosY, &m_fMoveEndPosY);




	//Move(m_tInfo.fX, m_tInfo.fY, 0.77f, 0.00f, 8.0f, 0.115f );
	return 0;
}

void CRensouhouZako::BulletPattern()
{		

	//m_fAngle += 20;
	
	
	CObj* pBullet = CObjFactory<CEnDirShooter>::CreateEnSpiral( m_tInfo.fX ,m_tInfo.fY, 0 , 0.f  , -5.5f, -0.03f);
	//CObj* pBullet = CObjFactory<CBullet>::CreateBullet(m_tInfo.fX ,m_tInfo.fY,m_fAngle);	
	((CBullet*)pBullet)->SetAttDir(OBJ_PLAYER);
	m_pBulletList->push_back(pBullet);

	
	//CObj* pEnBullet = CObjFactory<CEnDirShooter>::CreateObj(m_tInfo.fX - 20 ,m_tInfo.fY);	
	//m_pBulletList->push_back(pEnBullet);
	
	
	//m_cCreateMgr->CreateBullet(OBJ_ENEMY_DIRECTIONAL_BULLET,m_tInfo.fX - 20 ,m_tInfo.fY,CObj::m_fAngle);
	
	
}

