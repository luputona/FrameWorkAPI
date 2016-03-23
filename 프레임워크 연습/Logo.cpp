#include "StdAfx.h"
#include "Logo.h"
#include "Include.h"
#include <Vfw.h>
#pragma comment(lib,"vfw32.lib")
#include "StateMgr.h"


CLogo::CLogo(void) :
m_hVideo(NULL)
{
}


CLogo::~CLogo(void)
{
	Release();
}

void CLogo::Initialize()
{
	m_hVideo = MCIWndCreate(g_hWnd,NULL,MCIWNDF_NOPLAYBAR | WS_VISIBLE | WS_CHILD , L"../Video/Logo_1.wmv");

	MoveWindow(m_hVideo,0,0,WINCX,WINCY,NULL);
	MCIWndPlay(m_hVideo);
}

int CLogo::Progress()
{
	if(GetAsyncKeyState(VK_RETURN))
	{
		CStateMgr::GetInst()->SetState(IDS_MENU);
		return 0;
	}
	return 0;
}

void CLogo::Render(HDC hdc)
{

}

void CLogo::Release()
{
	MCIWndClose(m_hVideo);
}
