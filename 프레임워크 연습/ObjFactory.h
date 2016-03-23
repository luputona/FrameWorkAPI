#pragma once

class CObj;
class CBullet;
//class CRensouhouZako;
template <typename T>
class CObjFactory
{
public:
	static CObj* CreateObj()
	{
		CObj* pObj = new T;
		pObj->Initialize();
		return pObj;
	}

	static CObj* CreateObj(float _fx, float _fy)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		//pObj->Progress();
		pObj->SetPos(_fx,_fy);
	
		return  pObj;
	}
	static CObj* CreateObj1(float _fx, float _fy)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_fx,_fy);			
		

		return  pObj;
	}

	static inline CObj* CreateBullet(float _fx,float _fy, float _fAngle)
	{
		CObj* pBullet = new T;
		pBullet->Initialize();
		pBullet->SetPos(_fx,_fy);

		((CBullet*)pBullet)->SetAngle(_fAngle);

		return pBullet;
	}

	static CObj* CreateDirectionalBullet(float _fx, float _fy, float _fAngle, float _fAngleRate, float _fSpeed, float _fSpeedRate)
	{
		CObj* pObj = new T;
		pObj->Initialize();	
		pObj->SetPos(_fx,_fy);
		((CDirectionalShooter*)pObj)->SetSpeed(_fSpeed,_fSpeedRate);
		((CDirectionalShooter*)pObj)->SetAngle(_fAngle);
		((CDirectionalShooter*)pObj)->SetAngleRate(_fAngleRate);
		//((CBullet*)pObj)->SetAngle(_fAngle);
		//((CDirectionalShooter*)pObj)->TestDir();
		//((CDirectionalShooter*)pObj)->TestDir2(&_fAngle,&_fAngleRate,&_fSpeed,&_fSpeedRate);		

		return  pObj;
	}
	static inline CObj* CreateEnDir(float _fx, float _fy, float _fAngle, float _fAngleRate, float _fSpeed, float _fSpeedRate)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_fx,_fy);
		((CEnDirShooter*)pObj)->SetSpeed(_fSpeed,_fSpeedRate);
		((CEnDirShooter*)pObj)->SetAngle(_fAngle);
		((CEnDirShooter*)pObj)->SetAngleRate(_fAngleRate);
		//((CEnSpiral*)pObj)->SpiralBullet(&_fx,&_fy,&_fAngle,&_fAngleRate,&_fSpeed,&_fSpeedRate);

		return pObj;
	}
	static inline CObj* CreateEnSpiral(float _fx, float _fy, float _fAngle, float _fAngleRate, float _fSpeed, float _fSpeedRate)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_fx,_fy);
		((CEnSpiral*)pObj)->SetSpeed(_fSpeed,_fSpeedRate);
		((CEnSpiral*)pObj)->SetAngle(_fAngle);
		((CEnSpiral*)pObj)->SetAngleRate(_fAngleRate);
		//((CEnSpiral*)pObj)->SpiralBullet(&_fx,&_fy,&_fAngle,&_fAngleRate,&_fSpeed,&_fSpeedRate);

		return pObj;
	}

	static inline CObj* CreateMultipleSpiral(float _fx, float _fy, float _fAngle, float _fAngleRate, float _fSpeed, float _fSpeedRate)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_fx,_fy);
		((CEnSpiral*)pObj)->SetSpeed(_fSpeed,_fSpeedRate);
		((CEnSpiral*)pObj)->SetAngle(_fAngle);
		((CEnSpiral*)pObj)->SetAngleRate(_fAngleRate);
		//((CEnSpiral*)pObj)->SpiralBullet(&_fx,&_fy,&_fAngle,&_fAngleRate,&_fSpeed,&_fSpeedRate);

		return pObj;
	}

	static inline CObj* CreateRensouhou(float _fx, float _fy, float _fAngle, float _fAngleRate, float _fSpeed, float _fSpeedRate, float _fMovePosX, float _fMovePosY, float _fMoveEndPosY)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_fx,_fy);
		pObj->SetSpeed(_fSpeed,_fSpeedRate);
		pObj->SetAngle(_fAngle,_fAngleRate);
		pObj->SetMovePos(_fMovePosX,_fMovePosY,_fMoveEndPosY);
		((CRensouhouZako*)pObj)->Move(&_fx,&_fy,&_fAngle,&_fAngleRate,&_fSpeed,&_fSpeedRate,&_fMovePosX,&_fMovePosY,&_fMoveEndPosY);


		return pObj;
	}



	/*static inline CObj* CreateBullet(BULLET_DIRECTION _eBullet_direction, float _fx, float _fy, float _fAngle, float _fAngle_rate, float _fSpeed, float _fSpeed_rate)
	{
	CObj* pObj = new T;
	pObj->Initialize();

	return pObj;
	}*/

public:
	CObjFactory(){};
	~CObjFactory(){};

};