#pragma once
#include "Include.h"

class CKeyMgr
{
private:
	DWORD m_dwKey;
	DWORD m_dwTime;

public:
	DWORD GetKey(void)const { return m_dwKey; }
public:
	void CheckKey();
private:
	static CKeyMgr* m_pInst;
public:
	static CKeyMgr* GetInst()
	{
		if (m_pInst == NULL)
		{
			m_pInst = new CKeyMgr;
		}
		return m_pInst;
	}
	void DestroyInst()
	{
		Safe_Delete(m_pInst);
	}

public:
	CKeyMgr(void);
	~CKeyMgr(void);
};

