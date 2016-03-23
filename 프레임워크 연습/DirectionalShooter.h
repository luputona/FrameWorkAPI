#pragma once
#include "Obj.h"
#include "Bullet.h"


class CDirectionalShooter : public CBullet
{	
private:
	CObj* m_pPos;

	float m_fAngle;
	float m_fSpeed;
	float m_fSpeedRate;

	OBJID m_eAttTarget;
public:	
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
	virtual void SetAttDir(OBJID _edir) { m_eAttDir = _edir; }
	

	void SetAngle(float _fAngle) { m_fAngle = _fAngle; }
	void SetAngleRate(float _fAngleRate) { m_fAngleRate = _fAngleRate; }
	void SetSpeed(float _fSpeed, float _fSpeedRate) { m_fSpeed = _fSpeed; m_fSpeedRate = _fSpeedRate;}	

	void TestDir();
	void TestDir2(float* _fAngle, float* _fAngleRate,float* _fSpeed, float* _fSpeedRate);
public:
	CDirectionalShooter(void);
	virtual ~CDirectionalShooter(void);
};

