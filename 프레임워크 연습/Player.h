#pragma once
#include "Obj.h"
#include "Enum.h"

class CBullet;
class CPlayer : public CObj
{
private:
	list<CObj*>* m_pBulletList;
	string m_strDrawID;
	CBullet* m_pBullet;
	OBJID m_eTarget;

	CObj* pBullet;
	float m_f;
	
	float m_fAngle;
	//float m_fSpeed;

	DWORD m_dwKey;
	//DWORD m_dwTime;
	//DWORD m_dwState;
	//FRAME m_tFrame;

	bool bAlive;
public:
	void CheckKey();
	void Frame();
	void Direction();
	void Motion();

	void SetBulletPattern();
	
	void SetBullet(list<CObj*>* _pbullet){ m_pBulletList = _pbullet; }

	float GetPosX();
	float GetPosY();
	CObj* CreateBullet(OBJID _edir);


public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CPlayer(void);
	virtual ~CPlayer(void);
};

