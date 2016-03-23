#include "StdAfx.h"
#include "StageBack.h"


CStageBack::CStageBack(void) :
m_nScroll(0)
{
}


CStageBack::~CStageBack(void)
{
	Release();
}

void CStageBack::Initialize()
{
	m_tInfo.fX = 0;
	m_tInfo.fY = 0;
	m_tInfo.fCX = 3008;
	m_tInfo.fCY = 600;


}

int CStageBack::Progress()
{
	m_nScroll -= 3;

	if (-m_tInfo.fCX > m_nScroll)
	{
		m_nScroll = 0;
	}

	return 0;
}

void CStageBack::Render(HDC hdc)
{
	BitBlt(hdc,
		int(m_tInfo.fX + m_nScroll), (int)m_tInfo.fY, (int)m_tInfo.fCX, (int)m_tInfo.fCY,
		(*m_pMapBmp)["StageBackGround"]->GetMemDC(),
		0,0,SRCCOPY);

	BitBlt(hdc,
		int((m_tInfo.fX + m_tInfo.fCX) + m_nScroll), (int)m_tInfo.fY, (int)m_tInfo.fCX, (int)m_tInfo.fCY,
		(*m_pMapBmp)["StageBackGround"]->GetMemDC(),
		0,0,SRCCOPY);


	//BitBlt(hdc,0,0,WINCX,WINCY,(*m_pMapBmp)["BackGround"]->GetMemDC(),0,0,SRCCOPY);
}

void CStageBack::Release()
{

}
