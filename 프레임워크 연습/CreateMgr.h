#pragma once

#include "Enum.h"

class CObj;
class CCreateMgr
{
private:
	list<CObj*>* m_pEnBulletList;
	list<CObj*>* m_pEnemy;

	DWORD	m_dwTime;
	DWORD	m_dwDefault;
	DWORD	m_dwCreateTime;	//생성 시작 시간
	DWORD	m_dwTickTime;	//생성 간격
	int		m_nNumber;		//생성수

	DWORD	m_dwDelayTime;	//다음 생성 시간

public:
	void SetBullet(list<CObj*>* _pEnBulletList) { m_pEnBulletList = _pEnBulletList; }
	void SetEnemy(list<CObj*>* _pEnemy) { m_pEnemy = _pEnemy; }
	
	void CreateBullet(OBJID _eObjBulletID, float _fx, float _fy, float _fAngle);
	void CreateEnemy();
	void Initialize();
public:
	CCreateMgr(void);
	~CCreateMgr(void);
};

