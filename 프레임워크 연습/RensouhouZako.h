#pragma once
#include "Obj.h"
#include "Enemy.h"
#include "Enum.h"


class CDirectionalShooter;

class CEnemy;
class CRensouhouZako : public CEnemy
{
private:	
	CEnemy* m_Enemy;
	list<CObj*> m_pEnBulletList[OBJ_END];
	OBJID m_eAttDir;

public:
	
	void Move(float* _fx, float* _fy, float* _fAngle, float* _fAngleRate,  float* _fSpeed, float* _fSpeedRate, float* _fMovePosX, float* _fMovePosY,float* _fMoveEndPosY);

	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();


	virtual void SetBullet(list<CObj*>* _pbullet){ CEnemy::m_pBulletList = _pbullet; }
	void BulletPattern();
public:
	CRensouhouZako(void);
	virtual ~CRensouhouZako(void);
};

