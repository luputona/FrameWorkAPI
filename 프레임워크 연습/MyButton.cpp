#include "StdAfx.h"
#include "MyButton.h"
#include "Mouse.h"
#include "StateMgr.h"
#include "KeyMgr.h"

CMyButton::CMyButton(void)
{
}


CMyButton::~CMyButton(void)
{
	Release();
}

void CMyButton::Initialize()
{
	m_tInfo.fCX = 370;
	m_tInfo.fCY = 115;
	m_nScene = 0;

}

int CMyButton::Progress()
{
	if (PtInRect(&GetRect(),CMouse::GetPos()))
	{
		m_nScene = 1;
		if (CKeyMgr::GetInst()->GetKey() & KEY_LBUTTON)
		{
			if (m_strDrawID == "Start")
			{
				return 1;
			}
		}
	}
	else
		m_nScene = 0;

	return 0;
}

void CMyButton::Render(HDC hdc)
{
	TransparentBlt(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX/2),
		int(m_tInfo.fY - m_tInfo.fCY/2),
		(int)m_tInfo.fCX,(int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strDrawID]->GetMemDC(),
		int(m_tInfo.fCX * m_nScene),0,m_tInfo.fCX, m_tInfo.fCY,NULL);
}

void CMyButton::Release()
{

}
