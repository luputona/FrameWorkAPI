#include "StdAfx.h"
#include "DirectionalShooter.h"
#include "Bullet.h"
#include "Obj.h"
#include "Player.h"
#include "CircleCol.h"

CDirectionalShooter::CDirectionalShooter(void)
{
	Initialize();
}

CDirectionalShooter::~CDirectionalShooter(void)
{
	Release();
}

void CDirectionalShooter::Initialize()
{
	CObj* test = new CBullet;

	m_tInfo.fCX = 53;
	m_tInfo.fCY = 12;
	

  /*	m_fAngle = test->GetAngle();
	m_fAngleRate = test->GetAngleRate();
	
	m_fSpeed = test->GetSpeed();
	m_fSpeedRate = test->GetSpeedRate();*/


	m_strBulletID = "DIRECTIONAL";

	m_dwTime = GetTickCount();

	m_nInterval = 10;
	m_nCount = 1;
	m_nTime = 0;
}

void CDirectionalShooter::Render( HDC hdc )
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2 ) + 40.f,
		int(m_tInfo.fY - m_tInfo.fCY /2 ),
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strBulletID]->GetMemDC(),
		0,0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,RGB(255,0,216));
}

int CDirectionalShooter::Progress()
{	
	TestDir();

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

	//if (CCircleCol::CircleCollision(this, m_eAttDir))
	//{
	//	delete this;
	//	return 1;
	//}


	//TestDir2(&m_fAngle,&m_fAngleRate,&m_fSpeed,&m_fSpeedRate);
	return 0;
}

void CDirectionalShooter::Release()
{

}

void CDirectionalShooter::TestDir()
{
	m_tInfo.fX += cosf(m_fAngle * PI /180) * m_fSpeed;
	m_tInfo.fY += -sinf(m_fAngle * PI / 180) * m_fSpeed;

	//if (m_dwTime + 10 < GetTickCount())
	//{
		//m_dwTime = GetTickCount();

		//각도에 각속도 계산
		m_fAngle += m_fAngleRate;

		//속도에 가속도 가산
		m_fSpeed += m_fSpeedRate;
	//}
}

void CDirectionalShooter::TestDir2(float* _fAngle, float* _fAngleRate,float* _fSpeed, float* _fSpeedRate)
{
	//m_fRad = *_fAngle *PI *2;

	//m_tInfo.fX += *_fSpeed * cosf(m_fRad);
	//m_tInfo.fY += *_fSpeed * sinf(m_fRad);

	m_tInfo.fX += cosf(*_fAngle * PI /180) * *_fSpeed;
	m_tInfo.fY += -sinf(*_fAngle * PI /180) * *_fSpeed;

	//각도에 각속도 계산
	*_fAngle += *_fAngleRate;

	//속도에 가속도 가산
	*_fSpeed +=  *_fSpeedRate;

}
