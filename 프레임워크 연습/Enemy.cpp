#include "StdAfx.h"
#include "Enemy.h"

#include "ObjFactory.h"
#include "Bullet.h"
#include "RensouhouZako.h"
#include "DirectionalShooter.h"
#include "CreateMgr.h"


CEnemy::CEnemy(void)
{
}



CEnemy::~CEnemy(void)
{
	Release();
}

void CEnemy::Initialize()
{	
	
	/*
	m_tInfo = INFO(2500,100,30,50);


	m_fAngle = 0.77f;
	m_fAngleRate = 0.00f;

	m_fSpeed = 8.0f;
	m_fSpeedRate = 0.115f;

	m_dwTime = 0;

	m_strEnemyID = "RensouhouZako1";
	*/

}

int CEnemy::Progress()
{
	Frame();
	Direction();
	Motion();


	return 0;
}

void CEnemy::Render(HDC hdc)
{
/*
	
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2 ),
		int(m_tInfo.fY - m_tInfo.fCY /2 ),
		(int)m_tInfo.fCY, (int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strEnemyID]->GetMemDC(),
		0,0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,RGB(255,255,255));
		*/
}
void CEnemy::MoveEnemy()
{
	/*
	//������ ���� ������ ��ȯ
	m_fRad = m_fAngle * PI * 2;
	
	m_tInfo.fX -= m_fSpeed;

	if ( m_dwTime + 107 < GetTickCount())
	{
		m_dwTime = GetTickCount();

		m_fSpeed -= m_fSpeedRate;	
		
		if (m_fSpeed == 0 )
		{
			m_fSpeed += m_fSpeedRate;//�ӵ��� ���ӵ� ����			
		}
		
	}	
	if (  m_fSpeed <0 )
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fRad);
		m_tInfo.fY += m_fSpeed * sinf(m_fRad);//������ �ӵ��� ����ؼ� ��ǥ ����	

		m_fSpeedRate += 0.04;
		m_fAngle += m_fAngleRate; //������ ���ӵ� ���
		return;
	}
	*/
	

	//if (m_bCheckMove == true)
	//{
	//	m_tInfo.fX += m_fSpeed * cosf(m_fRad);
	//	m_tInfo.fY += m_fSpeed * sinf(m_fRad);//������ �ӵ��� ����ؼ� ��ǥ ����	

	//	m_fAngle += m_fAngleRate; //������ ���ӵ� ���
	//}
	//

	
	//m_fAngle += m_fSpeedRate;		
	//m_fAngle += m_fAngleRate;
	
}


void CEnemy::Release()
{

}

void CEnemy::Frame()
{

}

void CEnemy::Direction()
{

}

void CEnemy::Motion()
{

}

