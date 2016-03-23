#include "StdAfx.h"
#include "Ryujo.h"
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
CRyujo::CRyujo(void) :
m_bBulletCheck(false)
{
}


CRyujo::~CRyujo(void)
{
	Release();
}

void CRyujo::Initialize()
{

	m_tInfo.fCX = 200;
	m_tInfo.fCY = 200;

	m_fAngle = 0.f;
	m_fAngleRate = 0.00f;

	m_fa = 180;

	m_fSpeed = 6.0f;
	m_fSpeedRate = 0.095f;

	m_fMoveAngle = 45;

	m_strEnemyID = "Ryujo";
	

	m_dwDefault = GetTickCount();
	m_dwTime = GetTickCount();

	m_dwCreateTime = 5000;
	m_dwTickTime = 200;
	m_nNumber = 5;

	m_dwDelayTime  = 3000;

}

int CRyujo::Progress()
{
	//BulletPattern();
	Move();

	



	return 0;
}

void CRyujo::Render(HDC hdc)
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2 ),
		int(m_tInfo.fY - m_tInfo.fCY /2 ),
		(int)m_tInfo.fCY, (int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strEnemyID]->GetMemDC(),
		0,0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,RGB(255,0,216));
}

void CRyujo::Release()
{

}

void CRyujo::BulletPattern()
{
	m_fAngle += 9;

	m_fa -= 9;
	CObj* pBullet = CObjFactory<CEnSpiral>::CreateEnSpiral(m_tInfo.fX - 70, m_tInfo.fY -20 ,m_fAngle, 0.f, 2, 0.01f );
	((CBullet*)pBullet)->SetAttDir(OBJ_PLAYER);


	CObj* pBullet1 = CObjFactory<CEnSpiral>::CreateEnSpiral(m_tInfo.fX - 70, m_tInfo.fY -20 ,m_fa, 0.f, 2, 0.01f );
	((CBullet*)pBullet1)->SetAttDir(OBJ_PLAYER);

	//CObj* pBullet = CObjFactory<CMultipleSpiral>::CreateMultipleSpiral(m_tInfo.fX - 70, m_tInfo.fY -20 ,m_fAngle, 0.f, 4, 0.01f );
	//((CBullet*)pBullet)->SetAttDir(OBJ_PLAYER);
	
	m_pBulletList->push_back(pBullet);
	m_pBulletList->push_back(pBullet1);
}

void CRyujo::Move()
{

	m_fRad = m_fMoveAngle * PI  / 180;

	m_tInfo.fX -= m_fSpeed;

	if (m_dwTime + 100 < GetTickCount())
	{
		m_dwTime = GetTickCount();

		m_fSpeed -= m_fSpeedRate;
	}

	if ( (m_tInfo.fX  <= 500 && m_tInfo.fY <= 300)  )
	{
		m_fSpeedRate = 0;
		m_fSpeed = 0;
		
		BulletPattern();
				
		if (m_fAngle >= 2000 )
		{
			m_fSpeed += 4;
			m_fSpeedRate = 0.5f;
			//m_fMoveAngle += m_fAngleRate;

			m_tInfo.fX += m_fSpeed * cosf(m_fRad);
			m_tInfo.fY += m_fSpeed * -sinf(m_fRad);

			m_fSpeed += m_fSpeedRate;

		}	
		
	}
	
}
