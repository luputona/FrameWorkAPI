#include "StdAfx.h"
#include "Player.h"

#include "KeyMgr.h"
#include "ObjFactory.h"
#include "Bullet.h"
#include "DirectionalShooter.h"
#include "EnSpiral.h"
#include "Enum.h"

#include "EnDirShooter.h"

CPlayer::CPlayer(void) : 
bAlive(false),
m_pBullet(NULL)
{
	
}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize()
{

	m_tInfo = INFO(200,WINCY/2,100,100);
	m_tFrame = FRAME(0,0,0,0);
	m_dwState = STATE_STAND;

	m_f = 4.f;
	m_fAngle = 0.f;
	m_fSpeed = 7.0f;
	m_dwKey = 0;

	m_dwTime = GetTickCount();

	m_strDrawID = "Player_IDLE";
	
	
	
}

int CPlayer::Progress()
{
	CheckKey();
	Frame();
	Direction();
	Motion();



	return 0;
}

void CPlayer::Render(HDC hdc)
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX/2),
		int(m_tInfo.fY - m_tInfo.fCY/2),
		(int)m_tInfo.fCX,(int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strDrawID]->GetMemDC(),
		int(m_tInfo.fCX * m_tFrame.nStart),
		int(m_tInfo.fCY * m_tFrame.nScene),
		(int)m_tInfo.fCX,(int)m_tInfo.fCY,
		RGB(98,124,76));
}

void CPlayer::Release()
{

}

void CPlayer::CheckKey()
{
	m_dwKey = CKeyMgr::GetInst()->GetKey();

	if (m_dwKey & KEY_UP)
		m_tInfo.fY -= m_fSpeed;

	if(m_dwKey & KEY_DOWN)
		m_tInfo.fY += m_fSpeed;

	if (m_dwKey & KEY_LEFT)
	{
		m_tInfo.fX -= m_fSpeed;
		//m_dwState = STATE_MOVEBACK;
	}
		
	if(m_dwKey & KEY_RIGHT)
		m_tInfo.fX += m_fSpeed;

	
	if (m_dwKey & KEY_SPACE  )
	{
		
		SetBulletPattern();
		//m_pBulletList->push_back(CreateBullet(OBJ_ENEMY_DIRECTIONAL_BULLET));
		m_dwState = STATE_ATT;
	}
}

void CPlayer::SetBulletPattern()
{ 	
	//m_fAngle += 4; // m_fAngle에 각속도를 더함	
		
	pBullet = CObjFactory<CDirectionalShooter>::CreateDirectionalBullet(m_tInfo.fX +20 ,m_tInfo.fY, 0 , 0 , 12.0f, 0.0f);	
	//((CBullet*)pBullet)->SetAttDir(m_eTarget);
	((CBullet*)pBullet)->SetAttDir(OBJ_RENSOUHOU_ZAKO_1);
	m_pBulletList->push_back(pBullet);
	//if (m_eTarget == OBJ_Ryujo)
	//{
	//	((CBullet*)pBullet)->SetAttDir(OBJ_Ryujo);
	//	m_pBulletList->push_back(pBullet);
	//	return;
	//}
	//else if (m_eTarget == OBJ_RENSOUHOU_ZAKO_1)
	//{
	//	((CBullet*)pBullet)->SetAttDir(OBJ_RENSOUHOU_ZAKO_1);
	//	m_pBulletList->push_back(pBullet);
	//	return;
	//}






	/*switch(m_eTarget)
	{
	case OBJ_Ryujo :
		((CBullet*)pBullet)->SetAttDir(OBJ_Ryujo);
		m_pBulletList->push_back(pBullet);
		break;
	case OBJ_RENSOUHOU_ZAKO_1:
		((CBullet*)pBullet)->SetAttDir(OBJ_RENSOUHOU_ZAKO_1);
		m_pBulletList->push_back(pBullet);
		break;
	}*/


	//m_pBulletList->push_back(pBullet);
	

	//CObj* pBullet = CObjFactory<CBullet>::CreateBullet(m_tInfo.fX ,m_tInfo.fY,m_fAngle);		
	//m_pBullet = new CBullet;
	//m_pBullet->Progress();
	
}


void CPlayer::Frame()
{
	if (m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();

		++m_tFrame.nStart;

		if (m_tFrame.nStart >= m_tFrame.nLast)
		{
			m_tFrame.nStart = 0;
			if (m_dwTime != STATE_WALK && m_dwTime != STATE_MOVEBACK)
			{
				m_dwState = STATE_STAND;
			}
		}
	}

}

void CPlayer::Direction()
{
	if ( KEY_LEFT & m_dwKey || ( KEY_LEFT & m_dwKey && KEY_UP & m_dwKey ) ||  (KEY_LEFT & m_dwKey && KEY_DOWN & m_dwKey) )
	{
		m_strDrawID = "Player_MOVEBACK";
	}
	else if (  KEY_RIGHT & m_dwKey  || KEY_UP & m_dwKey  || KEY_DOWN & m_dwKey )
	{		
		m_strDrawID = "Player_MOVE";
	}	
	else
		m_strDrawID = "Player_IDLE";

	//화면 벗어나지 않게 제어
	if (m_tInfo.fY > 560 )
	{
		m_tInfo.fY = 560.f;
	}
	if (m_tInfo.fY < 25.0f)
	{
		m_tInfo.fY = 25.f;
	}
	if (m_tInfo.fX > 780)
	{
		m_tInfo.fX = 780.f;
	}
	if (m_tInfo.fX < 40.f)
	{
		m_tInfo.fX = 40.f;
	}


	//if (KEY_RIGHT & m_dwKey)
	//{
	//	m_strDrawID = "Player_RIGHT";
	//}
	//if (KEY_UP & m_dwKey)
	//{
	//	m_strDrawID = "Player_UP";
	//}
	//if (KEY_DOWN & m_dwKey)
	//{
	//	m_strDrawID = "Player_DOWN";
	//}
}

void CPlayer::Motion()
{
	if (m_dwKey && m_dwState != STATE_ATT)
	{
		m_dwState = STATE_WALK;
	}	
	/*if (!m_dwState)
	{
	m_dwState = STATE_STAND;
	}*/

	if (m_dwState & STATE_STAND)
	{
		if (m_tFrame.nScene != 0)
		{
			m_tFrame.nStart = 0;
		}

		m_tFrame.nLast = 13;
		m_tFrame.nScene = 0;
		m_tFrame.dwTime = 50;
	}

	if (m_dwState & STATE_WALK)
	{
		if (m_tFrame.nScene != 0)
		{
			m_tFrame.nStart = 0;
		}
		m_tFrame.nLast = 6;
		m_tFrame.nScene = 0;
		m_tFrame.dwTime = 50;
	}

	if (m_dwState & STATE_MOVEBACK)
	{
		if (m_tFrame.nScene != 0)
		{
			m_tFrame.nStart = 0;
		}
		m_tFrame.nLast = 5;
		m_tFrame.nScene = 0;
		m_tFrame.dwTime = 50;
	}

}

CObj* CPlayer::CreateBullet(OBJID _edir)
{
	CObj* pBullet = new CBullet;

	pBullet->SetPos(m_fX,m_fY);
	((CBullet*)pBullet)->SetAttDir(_edir);


	return pBullet;
}

float CPlayer::GetPosX()
{
	return m_tInfo.fX;
}

float CPlayer::GetPosY()
{
	return m_tInfo.fY;
}

