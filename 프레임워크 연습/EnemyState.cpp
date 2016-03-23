#include "StdAfx.h"
#include "EnemyState.h"

#include "ObjFactory.h"
#include "StageBack.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "RensouhouZako.h"
#include "ObjMgr.h"
#include "CreateMgr.h"

#include "Single.h"
#include "CircleCol.h"

CEnemyState::CEnemyState(void)
{
}


CEnemyState::~CEnemyState(void)
{
}

void CEnemyState::Initialize()
{

	//������ ����
	m_MapBmp["RensouhouZako1"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Monster/zako_1.bmp");

	//�� ź
	m_MapBmp["Enemy_DIRECTIONAL"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Bullet/EnemyBullet.bmp");


	CObj* pRensouho_1[3];
	//������ ��ü ����
	//CreateObj(����x,����y,����,���ӵ�,�ӵ�,���ӵ�,x����&��,y����.y��);
	for (int i = 0; i<3; ++i)
	{
		pRensouho_1[i] = CObjFactory<CRensouhouZako>::CreateObj(2400 + i * 100, 150 + i * 20 , -0.77f, 0.0f, 8.7f, 0.135f, 650.0f, 151.0f + i * 20, 300.0f);
		m_ObjList[OBJ_RENSOUHOU_ZAKO_1].push_back(pRensouho_1[i]);
		((CRensouhouZako*)pRensouho_1[i])->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);//ź���� 
	}	

	//������ ��ü ����
	CObj* pRensouho_2  = CObjFactory<CRensouhouZako>::CreateObj(3800,50,-0.77f,0.0f,25.40f,0.705f,700.0f,51.0f,200.0f);
	m_ObjList[OBJ_RENSOUHOU_ZAKO_1].push_back(pRensouho_2);
	((CRensouhouZako*)pRensouho_2)->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);//ź����


	CObj* pRensouho_3[3];
	for (int i = 0; i<3; ++i)
	{
		//������ ��ü ����
		pRensouho_3[i]  = CObjFactory<CRensouhouZako>::CreateObj(3000 + i * 100 ,500 - (i * 20) , 0.97f , 0.0f, 8.9f, 0.105f, 700.0f, 101.0f , 400.0f - (i * 20));
		m_ObjList[OBJ_RENSOUHOU_ZAKO_1].push_back(pRensouho_3[i]);
		((CRensouhouZako*)pRensouho_3[i])->SetBullet(&m_ObjList[OBJ_ENEMY_DIRECTIONAL_BULLET]);//ź����
	}
	CObj::SetBmp(&m_MapBmp);
}

int CEnemyState::Progress()
{
	

	return 0;
}

void CEnemyState::Render(HDC hdc)
{
	
}

void CEnemyState::Release()
{

}
