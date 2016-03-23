#include "StdAfx.h"
#include "Stage.h"
#include "ObjFactory.h"
#include "StageBack.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "RensouhouZako.h"
#include "ObjMgr.h"
#include "CreateMgr.h"
#include "EnemyState.h"
#include "Ryujo.h"
#include "ErrorKo.h"


#include "Single.h"
#include "CircleCol.h"

CStage::CStage(void) : 
m_pBackGround(NULL),
m_pCreateMgr(NULL),
m_pEnemy(NULL)
{
	
}


CStage::~CStage(void)
{
	Release();
}

void CStage::Initialize()
{

	m_MapBmp["BackBuffer"] = (new CBitMap)->LoadBmp(L"../Texture/BackBuffer.bmp");
	m_MapBmp["StageBackGround"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Back/BackGround_1.bmp");
	m_MapBmp["Player_IDLE"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/Idle/Idle.bmp");
	m_MapBmp["Player_MOVE"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/Move Forward/Move.bmp");
	m_MapBmp["Player_MOVEBACK"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/Move Back/MoveBack.bmp");

	//플레이어 탄
	m_MapBmp["DIRECTIONAL"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Bullet/PlayerDefaultBullet3.bmp");


	//연장포 자코
	m_MapBmp["RensouhouZako1"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Monster/zako_1.bmp");

	//류죠
	m_MapBmp["Ryujo"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Monster/Ryujo.bmp");

	//에러코
	m_MapBmp["ErrorKo"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Monster/Errorko.bmp");

	//적 탄
	m_MapBmp["Enemy_DIRECTIONAL"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Bullet/EnemyBullet.bmp");
	m_MapBmp["Enemy_SPIRAL"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Bullet/1EnemyBullet_2.bmp");
	m_MapBmp["Enemy_MultipleSprial"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Bullet/EnemyBullet_4.bmp");
		
	//배경
	m_pBackGround = CObjFactory<CStageBack>::CreateObj();

	//플레이어 객체 생성 
	CObj* pPlayer = CObjFactory<CPlayer>::CreateObj();
	((CPlayer*)pPlayer)->SetBullet(&m_ObjList[OBJ_DIRECTIONAL_BULLET]); //탄 생성 
	m_ObjList[OBJ_PLAYER].push_back(pPlayer);
		
	
	CObj* pRyujo = CObjFactory<CRyujo>::CreateObj(1700,250);
	((CRyujo*)pRyujo)->SetBullet(&m_ObjList[OBJ_ENEMY_SPIRAL_BULLET]);//탄생성
	m_ObjList[OBJ_Ryujo].push_back(pRyujo);
	

	CObj* pErrorko = CObjFactory<CErrorKo>::CreateObj(-2000, 250);
	((CErrorKo*)pErrorko)->SetBullet(&m_ObjList[OBJ_INTERVAL_MULTIPLE_SPIRAL]);
	m_ObjList[OBJ_ErrorKo].push_back(pErrorko);
	


	CreateRenshouhou();
	
	m_dwTime = 0;
	






	/*m_pCreateMgr = new CCreateMgr;
	m_pCreateMgr->Initialize();
	m_pCreateMgr->SetEnemy(&m_ObjList[OBJ_RENSOUHOU_ZAKO_1]);
	m_pCreateMgr->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);
	*/
	CObjMgr::GetInst()->SetObj(m_ObjList);
	
	CObj::SetBmp(&m_MapBmp);

}

int CStage::Progress()
{
	//m_pCreateMgr->CreateEnemy();
	
	m_pBackGround->Progress();

	for (int i = 0; i<OBJ_END; ++i)
	{
		for (list<CObj*>::iterator iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();)
		{
			int nResult = (*iter)->Progress();

			if (nResult == 1)
			{
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;			
		}
	}



	
	return 0;
}

void CStage::Render(HDC hdc)
{	
	m_pBackGround->Render(m_MapBmp["BackBuffer"]->GetMemDC());
	
	for (int i = 0; i<OBJ_END; ++i)
	{
		for (list<CObj*>::iterator iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_MapBmp["BackBuffer"]->GetMemDC());
		}
	}



	BitBlt(hdc, 0,0,WINCX,WINCY,
		m_MapBmp["BackBuffer"]->GetMemDC(),0,0,SRCCOPY);
}

void CStage::Release()
{
	CStateObj::Release();
	Safe_Delete(m_pBackGround);
	Safe_Delete(m_pCreateMgr);
	
	for (int i = 0; i<OBJ_END; ++i)
	{
		for (list<CObj*>::iterator iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			Safe_Delete(*iter);
		}
		m_ObjList[i].clear();
	}
		

}

void CStage::CreateRenshouhou()
{
	CObj* pRensouho_1[3];
	//연장포 객체 생성
	//CreateObj(생성x,생성y,각도,각속도,속도,가속도,x시작&끝,y시작.y끝);
	for (int i = 0; i<3; ++i)
	{
		pRensouho_1[i] = CObjFactory<CRensouhouZako>::CreateRensouhou(2400 + i * 100, 150 + i * 20 , -0.77f, 0.0f, 8.7f, 0.135f, 650.0f, 151.0f + i * 20, 300.0f);
			((CRensouhouZako*)pRensouho_1[i])->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);//탄생성
		m_ObjList[OBJ_RENSOUHOU_ZAKO_1].push_back(pRensouho_1[i]);
	
	}	

	//연장포 객체 생성
	CObj* pRensouho_2  = CObjFactory<CRensouhouZako>::CreateRensouhou(3800, 50, -0.77f, 0.0f, 25.40f, 0.705f, 700.0f, 51.0f, 200.0f);
	((CRensouhouZako*)pRensouho_2)->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);//탄생성
	m_ObjList[OBJ_RENSOUHOU_ZAKO_1].push_back(pRensouho_2);
	

	CObj* pRensouho_3[3];
	for (int i = 0; i<3; ++i)
	{
		//연장포 객체 생성
		pRensouho_3[i]  = CObjFactory<CRensouhouZako>::CreateRensouhou(3000 + i * 100 ,500 - (i * 20) , 0.97f , 0.0f, 8.9f, 0.105f, 700.0f, 101.0f , 400.0f - (i * 20));
		((CRensouhouZako*)pRensouho_3[i])->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);//탄생성
		m_ObjList[OBJ_RENSOUHOU_ZAKO_1].push_back(pRensouho_3[i]);
		
	}


	//연장포 객체 생성
	CObj* pRensouho_4  = CObjFactory<CRensouhouZako>::CreateRensouhou(3500, 260, -0.77f, 0.0f, 25.40f, 0.805f, 700.0f, 261.0f, 600.0f);
	((CRensouhouZako*)pRensouho_4)->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);//탄생성
	m_ObjList[OBJ_RENSOUHOU_ZAKO_1].push_back(pRensouho_4);
	


	//연장포 객체 생성
	CObj* pRensouho_5  = CObjFactory<CRensouhouZako>::CreateRensouhou(3000, 220, -0.77f, 0.0f, 25.40f, 0.905f, 700.0f, 221.0f, 570.0f);
	((CRensouhouZako*)pRensouho_5)->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);//탄생성
	m_ObjList[OBJ_RENSOUHOU_ZAKO_1].push_back(pRensouho_5);
	

	//CreateObj(생성x,생성y,각도,각속도,속도,가속도,x시작&끝,y시작.y끝);
//	CObj* pRensouho_6  = CObjFactory<CRensouhouZako>::CreateRensouhou(700,300,0,0,0,0,700,300,300);
//	((CRensouhouZako*)pRensouho_6)->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);//탄생성
//	m_ObjList[OBJ_RENSOUHOU_ZAKO_1].push_back(pRensouho_6);
	
	



}
