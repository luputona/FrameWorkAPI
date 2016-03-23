#pragma once
#include "Obj.h"


class CRensouhouZako;

class CEnemy : public CObj
{
public:
	//float m_fX;
	//float m_fY;
	//float m_fCX;
	//float m_fCY;
protected:
	list<CObj*>* m_pBulletList;
	string m_strEnemyID;
	OBJID m_eAttDir;
	
	
public:	
	void Frame();
	void Direction();
	void Motion();
	void MoveEnemy();


	virtual void SetBullet(list<CObj*>* _pbullet){ m_pBulletList = _pbullet; }
	
	//CObj* CreateBullet(OBJID _edir);
public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	CEnemy(void);
	virtual ~CEnemy(void);
};

