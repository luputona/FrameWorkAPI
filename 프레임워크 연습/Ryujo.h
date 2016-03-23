#pragma once
#include "Obj.h"
#include "Enemy.h"
#include "Enum.h"


class CRyujo : public CEnemy
{
private:
	list<CObj*> m_pEnBulletList[OBJ_END];
	float m_fMoveAngle;
	bool m_bBulletCheck;
	float m_fa;


public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
	virtual void SetBullet(list<CObj*>* _pbullet){ CEnemy::m_pBulletList = _pbullet; }
	void BulletPattern();
	void Move();
public:
	CRyujo(void);
	virtual ~CRyujo(void);
};

