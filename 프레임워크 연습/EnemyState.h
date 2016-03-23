#pragma once
#include "Stage.h"

class CObj;
class CRensouhouZako;
class CCreateMgr;
class CEnemyState : public CStage
{
private:
	

public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CEnemyState(void);
	~CEnemyState(void);
};

