#pragma once
#include "Obj.h"


class CDirectionalShooter;
class CBullet : public CObj
{
private:
	list<CObj*>* m_pBulletList;
	
	float m_fAngle;
protected:	
	list<CObj*> m_pEnemyList;

	float m_fBulletSpeed;
	float m_fAngleRate;	
	float m_fSpeedRate;
	
	float m_fCX;
	float m_fCY;

	int m_nInterval;
	int m_nCount;
	int m_nTime;


public:
	CDirectionalShooter* m_cDirShooter;
	
	OBJID m_eAttDir;
	string m_strBulletID;

	//DWORD m_dwKey;
	//DWORD m_dwTime;
	//DWORD m_dwState;

	
	void SetAngle(float _fAngle) { m_fAngle = _fAngle; }

	void TestPart();

	virtual void SetAttDir(OBJID _edir) { m_eAttDir = _edir; }
	virtual OBJID GetID() { return m_eAttDir; }
public:
	virtual void Initialize();
	virtual int Progress();	
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual void MoveBullet();
	
	

public:
	

public:
	CBullet(void);		
	virtual ~CBullet(void);
};

