#pragma once

#include "Enum.h"
class CObj;
class CCircleCol
{
public:
	static bool CircleCollision(CObj* _pSrc , OBJID _eIdType);
	static bool EnemyCollision( CObj* _pSrc, CObj* _pDst );
public:
	CCircleCol(void);
	~CCircleCol(void);
};

