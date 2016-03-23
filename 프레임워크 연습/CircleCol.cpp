#include "StdAfx.h"
#include "CircleCol.h"
#include "Obj.h"
#include "ObjMgr.h"


CCircleCol::CCircleCol(void)
{

}


CCircleCol::~CCircleCol(void)
{

}

bool CCircleCol::CircleCollision(CObj* _pSrc, OBJID _eIdType )
{
	list<CObj*>* pObjList = CObjMgr::GetInst()->GetObj(_eIdType);
	
	for (list<CObj*>::iterator iter = pObjList->begin(); iter != pObjList->end(); ++iter)
	{
		float fVecX = (*iter)->GetPosX() - _pSrc->GetPosX();
		float fVecY = (*iter)->GetPosY() - _pSrc->GetPosY();

		float fLength = sqrt(fVecX * fVecX + fVecY * fVecY);

		float fSum = ( (*iter)->GetInfo().fCX / 8 ) + (_pSrc->GetInfo().fCX / 8 ); //반지름 + 반지름 

		if (fLength < fSum ) //반지름끼리 합이 더 크면 충돌
		{
			if ( _eIdType == OBJ_PLAYER)
			{
				Safe_Delete(*iter);
				pObjList->erase(iter);
			}
			if (_eIdType == OBJ_RENSOUHOU_ZAKO_1)
			{
				Safe_Delete(*iter);
				pObjList->erase(iter);
			}
			if (_eIdType == OBJ_Ryujo)
			{
				Safe_Delete(*iter);
				pObjList->erase(iter);
			}

			return 1;
		}
	}

	return 0;
}

bool CCircleCol::EnemyCollision( CObj* _pSrc, CObj* _pDst )
{
	//list<CObj*>* pObjList1 = CObjMgr::GetInst()->GetObj(_eIdType);

	//for (list<CObj*>::iterator iter = pObjList1->begin(); iter != pObjList1->end(); ++iter)
	//{
		float fVecX = _pDst->GetPosX() - _pSrc->GetPosX();
		float fVecY = _pDst->GetPosY() - _pSrc->GetPosY();

		float fLength = sqrt(fVecX * fVecX + fVecY * fVecY);

		float fSum = ( _pDst->GetInfo().fCX / 12 ) + (_pSrc->GetInfo().fCX / 12 ); //반지름 + 반지름 

		if (fLength < fSum ) //반지름끼리 합이 더 크면 충돌
		{
			
			return 1;
		}
	//}		

	return 0;
}
