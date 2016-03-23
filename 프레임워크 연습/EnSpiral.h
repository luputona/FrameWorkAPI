#pragma once
#include "Obj.h"
#include "Bullet.h"

class CPlayer;

class CEnSpiral : public CBullet
{
private:
	float fRad;
	float m_fAngle;
	float m_fAngleRate;
	
	CPlayer* m_pPlayer;

	OBJID m_eAttTarget;
public:	
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual void SetAttDir(OBJID _edir) { m_eAttDir = _edir; }

	void test();

	int TestCol(CObj* _pDst, CObj* _pSrc);

	
	
	void SetAngle(float _fAngle) { m_fAngle = _fAngle; }
	void SetAngleRate(float _fAngleRate) { m_fAngleRate = _fAngleRate; }
	void SetSpeed(float _fSpeed, float _fSpeedRate) { m_fSpeed = _fSpeed; m_fSpeedRate = _fSpeedRate;}

	void SpiralBullet(float* _fx, float* _fy, float* _fAngle, float* _fAngleRate, float* _fSpeed, float* _fSpeedRate);
public:
	CEnSpiral(void);
	~CEnSpiral(void);
};

