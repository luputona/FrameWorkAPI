#include "StdAfx.h"
#include "Obj.h"

map<string,CBitMap*>* CObj::m_pMapBmp = NULL;

CObj::CObj(void) :
m_fAngleRate(0.0),
m_fSpeed(0.0),
m_fSpeedRate(0.0f),
m_fRad(0.0f),
m_dwTime(0),
m_dwState(0),
m_bAlive(false),
m_bCheckMove(false),
m_fMovePosX(0.0f),
m_fMovePosY(0.0f),
m_fMoveEndPosY(0.0f)
{
}


CObj::~CObj(void)
{
}

void CObj::SetPos(float _fx,float _fy)
{
	m_tInfo.fX = _fx;
	m_tInfo.fY = _fy;
}

void CObj::SetSpeed(float _fSpeed, float _fSpeedRate)
{
	m_fSpeed = _fSpeed;
	m_fSpeedRate = _fSpeedRate;
}

void CObj::SetAngle(float _fAngle, float _fAngleRate)
{
	m_fAngle = _fAngle;
	m_fAngleRate = _fAngleRate;
}
void CObj::SetMovePos(float _fMovePosX, float _fMovePosY, float _fMoveEndPosY)
{
	m_fMovePosX = _fMovePosX;
	m_fMovePosY = _fMovePosY;
	m_fMoveEndPosY = _fMoveEndPosY;
}

RECT CObj::GetRect()
{
	RECT rc = {
		m_tInfo.fX - m_tInfo.fCX/2,
		m_tInfo.fY - m_tInfo.fCY/2,
		m_tInfo.fX + m_tInfo.fCX/2,
		m_tInfo.fY + m_tInfo.fCY/2
	};

	return rc;
}


float CObj::GetRadius()
{
	return m_fRad;
}

void CObj::MoveBullet()
{

}

void CObj::TestDir2(float* _fAngle, float* _fAngleRate,float* _fSpeed, float* _fSpeedRate)
{

}


