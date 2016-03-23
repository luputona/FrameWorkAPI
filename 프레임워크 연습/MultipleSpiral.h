#pragma once
#include "Obj.h"
#include "Bullet.h"

class CMultipleSpiral : public CBullet
{
private:
	float m_fRad;
	float m_fAngle;
	float m_fAngleRate;

	OBJID m_eAttDir;

public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual void SetAttDir(OBJID _edir) { m_eAttDir = _edir; }

	void SetAngle(float _fAngle) { m_fAngle = _fAngle; }
	void SetAngleRate(float _fAngleRate) { m_fAngleRate = _fAngleRate; }
	void SetSpeed(float _fSpeed, float _fSpeedRate) { m_fSpeed = _fSpeed; m_fSpeedRate = _fSpeedRate;}
	void MultipleSpiral();

public:
	CMultipleSpiral(void);
	virtual ~CMultipleSpiral(void);
};

