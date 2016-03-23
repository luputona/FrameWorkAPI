#include "StdAfx.h"
#include "ErrorKo.h"
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
#include "MultipleSpiral.h"

CErrorKo::CErrorKo(void) : 
m_fMoveAngle(NULL)
{
}


CErrorKo::~CErrorKo(void)
{
	Release();
}

void CErrorKo::Initialize()
{
	m_tInfo.fCX = 200;
	m_tInfo.fCY = 200;
	
	m_fAngle = 0.f;
	m_fAngleRate = 0.0f;
	
	m_fSpeed = 9.0f;
	m_fSpeedRate = 0.095f;

	m_fMoveAngle = 180;

	m_strEnemyID = "ErrorKo";

	m_dwCreateTime = 5000;
	m_dwTickTime = 200;
	m_nNumber = 5;

	m_dwDelayTime  = 3000;

	
}

int CErrorKo::Progress()
{
	Move();

	return 0;
}

void CErrorKo::Render(HDC hdc)
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2 ),
		int(m_tInfo.fY - m_tInfo.fCY /2 ),
		(int)m_tInfo.fCY, (int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strEnemyID]->GetMemDC(),
		0,0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,RGB(255,0,216));
}

void CErrorKo::Release()
{

}

void CErrorKo::BulletPattern()
{
	m_fAngle += 8;

	CObj* pBullet = CObjFactory<CMultipleSpiral>::CreateMultipleSpiral(m_tInfo.fX - 70, m_tInfo.fY - 20, m_fAngle, 0.f, 5 , 0.0f);
	//CObj* pBullet = CObjFactory<CMultipleSpiral>::CreateBullet(m_tInfo.fX - 70, m_tInfo.fY - 20, m_fAngle);
	((CBullet*)pBullet)->SetAttDir(OBJ_PLAYER);
	m_pBulletList->push_back(pBullet);

}

void CErrorKo::Move()
{
	m_fRad = m_fMoveAngle * PI  / 180;

	m_tInfo.fX += m_fSpeed;

	if (m_dwTime + 100 < GetTickCount())
	{
		m_dwTime = GetTickCount();

		m_fSpeed -= m_fSpeedRate;
	}

	if ( (m_tInfo.fX  >= 350 )  )
	{
		m_fSpeedRate = 0;
		m_fSpeed = 0;

		BulletPattern();

		if (m_fAngle >= 4000 )
		{
			m_fSpeed = 8;
			m_fSpeedRate = 1.5f;
			//m_fMoveAngle += m_fAngleRate;

			m_tInfo.fX += m_fSpeed * cosf(m_fRad);
			m_tInfo.fY += m_fSpeed * -sinf(m_fRad);

			

		}	
		m_fSpeed += m_fSpeedRate;
	}
}
