#include "StdAfx.h"
#include "MainGame.h"
#include "StateMgr.h"
#include "KeyMgr.h"

CMainGame::CMainGame(void)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);


	CStateMgr::GetInst()->SetState(IDS_LOGO);
	
}

void CMainGame::Progress()
{
	CKeyMgr::GetInst()->CheckKey();

	CStateMgr::GetInst()->Progress();
}

void CMainGame::Render()
{

	CStateMgr::GetInst()->Render(m_hdc);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);
	CStateMgr::GetInst()->DestroyInst();
	CKeyMgr::GetInst()->DestroyInst();

}
