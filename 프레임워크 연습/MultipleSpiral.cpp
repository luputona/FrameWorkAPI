#include "StdAfx.h"
#include "MultipleSpiral.h"

#include "Player.h"
#include "Obj.h"
#include "ObjFactory.h"
#include "CircleCol.h"
CMultipleSpiral::CMultipleSpiral(void)
{
}


CMultipleSpiral::~CMultipleSpiral(void)
{
}

void CMultipleSpiral::Initialize()
{
	m_tInfo.fCX = 16;
	m_tInfo.fCY = 15;

	m_fAngle = 10.f;
	m_fAngleRate = 2.02f;

	//m_fSpeed = 5.0f;
	//m_fSpeedRate = 0.2f;

	m_strBulletID = "Enemy_MultipleSprial";

	m_dwTime = GetTickCount();
	m_dwBulletTime = GetTickCount();

	m_nInterval = 5;
	m_nCount = 4;
	m_nTime = 0;

}

int CMultipleSpiral::Progress()
{
	MultipleSpiral();

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

}

void CMultipleSpiral::Render(HDC hdc)
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2 ),
		int(m_tInfo.fY - m_tInfo.fCY /2 ),
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strBulletID]->GetMemDC(),
		0,0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,RGB(255,0,216));
}

void CMultipleSpiral::Release()
{

}

void CMultipleSpiral::MultipleSpiral()
{
	m_fRad = m_fAngle * PI  / 180;
	
	if (m_nTime == 0)
	{		
		
		//for (int i = 0; i<m_nCount; ++i)
		//{
			m_tInfo.fX += m_fSpeed * cosf(m_fRad);
			m_tInfo.fY += m_fSpeed * -sinf(m_fRad);
			
			//m_fAngle += (float)i/m_nCount;
			
			
		//}
		m_fSpeed += m_fSpeedRate;
		m_fAngle += m_fAngleRate;
	}
	
	m_nTime = (m_nTime+1)%m_nInterval;
}
