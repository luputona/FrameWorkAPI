#include "StdAfx.h"
#include "BitMap.h"
#include "Define.h"


CBitMap::CBitMap(void)
{
}


CBitMap::~CBitMap(void)
{
	Release();
}

CBitMap* CBitMap::LoadBmp(PTCHAR pFileName)
{
	m_hdc = GetDC(g_hWnd);

	m_MemDC = CreateCompatibleDC(m_hdc);

	//soen

	m_bitmap = (HBITMAP)LoadImage(NULL, pFileName,IMAGE_BITMAP
		,0,0,LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	m_oldbitmap = (HBITMAP)SelectObject(m_MemDC,m_bitmap);

	ReleaseDC(g_hWnd,m_hdc);

	return this;
}

void CBitMap::Release()
{
	SelectObject(m_MemDC,m_oldbitmap);
	DeleteObject(m_bitmap);
	DeleteDC(m_MemDC);
}
