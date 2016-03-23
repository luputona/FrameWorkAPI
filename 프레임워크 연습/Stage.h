#pragma once
#include "StateObj.h"

class CObj;
class CRensouhouZako;
class CCreateMgr;
class CEnemyState;
class CStage : public CStateObj
{
protected:
	list<CObj*> m_BulletList;	

	DWORD m_dwTime;

	CEnemyState* m_pEnemy;
	CObj* m_pBullet;
	CCreateMgr* m_pCreateMgr;
	CObj* m_pPlayer;
	CObj* m_pBackGround;
	list<CObj*> m_ObjList[OBJ_END];
public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	void CreateRenshouhou();

public:
	CStage(void);
	virtual ~CStage(void);
};

