#include "StdAfx.h"
#include "KeyMgr.h"

CKeyMgr* CKeyMgr::m_pInst = NULL;

CKeyMgr::CKeyMgr(void) : 
m_dwTime(0)
{
}


CKeyMgr::~CKeyMgr(void)
{
}

void CKeyMgr::CheckKey()
{
	m_dwKey = 0;

	if(GetAsyncKeyState(VK_UP) &0x8000)
	{
		m_dwKey |= KEY_UP;	
	}

	if(GetAsyncKeyState(VK_DOWN) &0x8000)
	{
		m_dwKey |= KEY_DOWN;
	}

	if(GetAsyncKeyState(VK_LEFT) &0x8000)
	{
		m_dwKey |= KEY_LEFT;
	}

	if(GetAsyncKeyState(VK_RIGHT) &0x8000)
	{
		m_dwKey |= KEY_RIGHT;
	}

	if(GetAsyncKeyState(VK_LBUTTON) &0x8000)
	{
		m_dwKey |= KEY_LBUTTON;
	}
	if(GetAsyncKeyState(VK_RBUTTON) &0x8000)
	{
		m_dwKey |= KEY_RBUTTON;
	}

	if (m_dwTime + 100 <GetTickCount())
	{
		m_dwTime = GetTickCount();
		if(GetAsyncKeyState(VK_SPACE) &0x8000)
		{
			m_dwKey |= KEY_SPACE;
		}
	}
	
	if(GetAsyncKeyState(VK_RETURN) &0x8000)
	{
		m_dwKey |= KEY_RETURN;
	}


}
