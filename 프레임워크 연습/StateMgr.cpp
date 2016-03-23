#include "StdAfx.h"
#include "StateMgr.h"

#include "Logo.h"
#include "MyMenu.h"
#include "Stage.h"

CStateMgr* CStateMgr::m_pInst = NULL;


CStateMgr::CStateMgr(void) :
m_pState(NULL)
{
}


CStateMgr::~CStateMgr(void)
{
}

void CStateMgr::SetState(STATEID _estate)
{
	::Safe_Delete(m_pState);

	switch(_estate)
	{
	case IDS_LOGO :
		m_pState = new CLogo;
		break;
	case IDS_MENU:
		m_pState = new CMyMenu;
		break;
	case IDS_STAGE:
		m_pState = new CStage;
		break;
	}
	m_pState->Initialize();
}

void CStateMgr::Progress()
{
	m_pState->Progress();
}

void CStateMgr::Render(HDC hdc)
{
	m_pState->Render(hdc);
}

void CStateMgr::Release()
{

}
