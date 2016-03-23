#pragma once
#include "Obj.h"
#include "Bullet.h"

class CPlayer;
class CEnDirShooter : public CBullet
{
private:
	CPlayer* pObjPos;
	float m_fAngle;

	OBJID m_eAttTarget;
public:
	void BulletMove();
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual void SetAttDir(OBJID _edir) { m_eAttDir = _edir; }

	void SetAngle(float _fAngle) { m_fAngle = _fAngle; }
	void DirectionalShooter();
public:
	CEnDirShooter(void);
	~CEnDirShooter(void);
};

