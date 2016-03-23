#pragma once
#include "Value.h"


class CBitMap
{
public:
	HDC		m_hdc,m_MemDC;
	HBITMAP	m_bitmap,m_oldbitmap;
public:
	CBitMap* LoadBmp(PTCHAR pFileName);
	void Release();
public:
	HDC GetMemDC(){return m_MemDC;}
public:
	CBitMap(void);
	~CBitMap(void);
};

