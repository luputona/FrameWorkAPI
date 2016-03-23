#pragma once
#include "StateObj.h"

class CObj;
class CMyMenu : public CStateObj
{
private:
	CObj* m_pBackGround;
	list<CObj*> m_ButtonList;
public:
	CObj* CreateButton(float _fx,float _fy,string _DrawID);
public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CMyMenu(void);
	virtual ~CMyMenu(void);
};

