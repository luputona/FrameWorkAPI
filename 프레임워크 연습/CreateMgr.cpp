#include "StdAfx.h"
#include "CreateMgr.h"

#include "ObjFactory.h"
#include "EnDirShooter.h"
#include "Enemy.h"
#include "Enum.h"
#include "Obj.h"
#include "ObjMgr.h"
#include "RensouhouZako.h"


CCreateMgr::CCreateMgr(void)
{
}


CCreateMgr::~CCreateMgr(void)
{
}
void CCreateMgr::Initialize()
{
	m_dwDefault = GetTickCount();
	m_dwTime = GetTickCount();

	m_dwCreateTime = 5000;
	m_dwTickTime = 200;
	m_nNumber = 5;

	m_dwDelayTime  = 3000;
}

void CCreateMgr::CreateBullet(OBJID _eObjBulletID, float _fx, float _fy, float _fAngle)
{
	if (m_dwDefault + m_dwCreateTime < GetTickCount())
	{
		m_dwCreateTime = 0;

		if (m_nNumber <= 5)
		{
			if (m_dwTime + m_dwTickTime < GetTickCount())
			{
				m_dwTime = GetTickCount();
				--m_nNumber;

				CObj* pEnBullet = CObjFactory<CRensouhouZako>::CreateObj(_fx ,_fy);
				((CRensouhouZako*)pEnBullet)->SetBullet(CObjMgr::GetInst()->GetObj(_eObjBulletID));

				m_pEnBulletList->push_back(pEnBullet);

				if (m_nNumber <=0 )
				{
					m_nNumber = 5;
					m_dwDefault = GetTickCount();
					m_dwCreateTime = m_dwDelayTime;
				}
			}
		}
	}
}


void CCreateMgr::CreateEnemy()
{
	if(m_dwDefault + m_dwCreateTime < GetTickCount())
	{
		m_dwCreateTime = 0;

		if(m_nNumber <= 5)
		{
			if(m_dwTime + m_dwTickTime < GetTickCount())
			{
				m_dwTime = GetTickCount();

				--m_nNumber;

				float	fX = WINCX + 10;
				float	fY = float((100 * m_nNumber) + 50);

				CObj* pEnemy = CObjFactory<CRensouhouZako>::CreateObj(fX, fY);
				((CRensouhouZako*)pEnemy)->SetBullet(CObjMgr::GetInst()->GetObj(OBJ_ENEMY_DIRECTIONAL_BULLET));

				m_pEnemy->push_back(pEnemy);

				if(m_nNumber <= 0)
				{
					m_nNumber = 5;
					m_dwDefault = GetTickCount();
					m_dwCreateTime = m_dwDelayTime;
				}
			}
		}
	}
}
