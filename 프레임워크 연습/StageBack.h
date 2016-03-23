#pragma once
#include "Obj.h"

class CStageBack : public CObj
{
private:
	int	m_nScroll;
public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CStageBack(void);
	virtual ~CStageBack(void);
};

