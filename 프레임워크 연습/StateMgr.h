#pragma once
#include "Include.h"

class CStateObj;
class CStateMgr
{
private:
	CStateObj*		m_pState;
public:
	virtual void SetState(STATEID _estate);
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	static CStateMgr* m_pInst;
public:
	static CStateMgr* GetInst()
	{
		if (m_pInst == NULL)
		{
			m_pInst = new CStateMgr;
		}
		return m_pInst;
	}
	void DestroyInst()
	{
		::Safe_Delete(m_pInst);
	}

public:
	CStateMgr(void);
	~CStateMgr(void);
};

