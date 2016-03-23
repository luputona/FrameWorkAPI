#pragma once
#include "Include.h"

class CObj
{	
protected:		
	DWORD	m_dwBulletTime;
	DWORD	m_dwTime;
	DWORD	m_dwState;

	DWORD	m_dwDefault;
	DWORD	m_dwCreateTime;	//���� ���� �ð�
	DWORD	m_dwTickTime;	//���� ����
	int		m_nNumber;		//������

	DWORD	m_dwDelayTime;	//���� ���� �ð�

	FRAME	m_tFrame;
	
	float	m_fSpeed;
	float	m_fSpeedRate;
	float	m_fAngle;
	float	m_fAngleRate;
	float	m_fRad;

	float	m_fMovePosX;
	float	m_fMovePosY;
	float	m_fMoveEndPosY;
	
	float	m_fX;
	float	m_fY;
	float	m_fCX;
	float	m_fCY;
	

	bool m_bAlive;
	bool m_bCheckMove;
		
	//SHAPE* m_tShape;		
	INFO	m_tInfo;

	static map<string,CBitMap*>* m_pMapBmp;	

public:
	INFO GetInfo(void)const { return m_tInfo; }
	RECT GetRect();

public:
	void SetPos(float _fx,float _fy);
	void SetSpeed(float _fSpeed, float _fSpeedRate);
	void SetAngle(float _fAngle, float _fAngleRate);
	void SetMovePos(float _fMovePosX, float _fMovePosY, float _fMoveEndPosY);
	float GetRadius();

	float GetAngle() {return m_fAngle;}
	float GetPosX() {return m_tInfo.fX;}
	float GetPosY() {return m_tInfo.fY;}
	float GetAngleRate() {return m_fAngleRate;}
	float GetSpeed() {return m_fSpeed;}
	float GetSpeedRate() {return m_fSpeedRate; }
		
	
	static void SetBmp(map<string, CBitMap*>* _pMapBmp){m_pMapBmp = _pMapBmp;}
	void TestDir2(float* _fAngle, float* _fAngleRate,float* _fSpeed, float* _fSpeedRate);
public:
	virtual void Initialize()PURE;
	virtual int Progress()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Release()PURE;

	virtual void MoveBullet();
	
public:
	CObj(void);	
	~CObj(void);
};

