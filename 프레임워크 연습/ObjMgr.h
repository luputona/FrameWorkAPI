#pragma once
#include "Single.h"

class CObj;
class CObjMgr : public CSingle<CObjMgr>
{
private:
	list<CObj*>* m_pObjList;

public:
	list<CObj*>* GetObj(OBJID _eObjID)
	{
		return &m_pObjList[_eObjID];
	}
public:
	void SetObj(list<CObj*>* _pObjList)
	{
		m_pObjList = _pObjList;
	}
public:
	CObjMgr(void);
	~CObjMgr(void);
};

