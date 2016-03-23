#include "StdAfx.h"
#include "EnDirShooter.h"
#include "Bullet.h"
#include "Obj.h"
#include "Player.h"
#include "CircleCol.h"

CEnDirShooter::CEnDirShooter(void) : 
pObjPos(NULL)
{
}


CEnDirShooter::~CEnDirShooter(void)
{
	Release();
}

void CEnDirShooter::BulletMove()
{

}

void CEnDirShooter::Initialize()
{
	m_tInfo.fCX = 16;
	m_tInfo.fCY = 16;

	//pObjPos = new CPlayer;
	//m_fX = pObjPos->GetPosX();
	//m_fY = pObjPos->GetPosY();


	m_fAngle = -0.01f;
	m_fAngleRate = -0.00f;

	m_fSpeedRate = -0.1f;
	m_fSpeed = -6.3f;

	m_strBulletID = "Enemy_DIRECTIONAL";

	m_dwTime = GetTickCount();
	m_dwBulletTime = GetTickCount();

	m_nInterval = 10;
	m_nCount = 1;
	m_nTime = 0;
}

int CEnDirShooter::Progress()
{	
	DirectionalShooter();	
	if (CCircleCol::CircleCollision(this, m_eAttDir))
	{
		delete this;
		return 1;
	}

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



	return 0;
}

void CEnDirShooter::Render(HDC hdc)
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2 ),
		int(m_tInfo.fY - m_tInfo.fCY /2 ),
		(int)m_tInfo.fCY, (int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strBulletID]->GetMemDC(),
		0,0,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,RGB(255,255,255));
}

void CEnDirShooter::Release()
{

}

void CEnDirShooter::DirectionalShooter()
{		
	//�⺻ źȯ

	//������ ���� ������ ��ȯ
	float fRad = m_fAngle * PI * 2; //ź�� �������� �ӵ��� ��� ź�� ��ǥ�� ����	
	

	//������ �ӵ��� ����ؼ� ��ǥ ����
	m_tInfo.fX += m_fSpeed * cosf(fRad);
	m_tInfo.fY += m_fSpeed * sinf(fRad);

	//������ ���ӵ� ���
	m_fAngle += m_fAngleRate;

	//�ӵ��� ���ӵ� ����
	m_fSpeed += m_fSpeedRate;

	
}
