#pragma once
#include "Obj.h"

class CMyButton : public CObj
{
private:
	string  m_strDrawID;
	int		m_nScene;
public:
	void SetDrawID(string _drawid) { m_strDrawID = _drawid; }
public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CMyButton(void);
	virtual ~CMyButton(void);
};

