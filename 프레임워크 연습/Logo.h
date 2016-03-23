#pragma once
#include "StateObj.h"

class CLogo : public CStateObj
{
private:
	HWND m_hVideo;
public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CLogo(void);
	virtual ~CLogo(void);
};

