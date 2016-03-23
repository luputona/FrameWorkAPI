#pragma once
#include "Obj.h"
#include "Enemy.h"
#include "Enum.h"


class CErrorKo : public CEnemy
{
private:
	CEnemy* m_pEnemy;
	list<CObj*> m_pEnBulletList[OBJ_END];
	OBJID m_eAttDir;
	float m_fMoveAngle;

public:

	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();


	virtual void SetBullet(list<CObj*>* _pbullet){ CEnemy::m_pBulletList = _pbullet; }
	void BulletPattern();
	void Move();

public:
	CErrorKo(void);
	~CErrorKo(void);
};

