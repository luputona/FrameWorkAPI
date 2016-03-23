#pragma once

typedef struct tagInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;

	tagInfo(){}
	tagInfo(float _fx,float _fy) : 
	fX(_fx), fY(_fy)
	{
	}
	tagInfo(float _fx,float _fy ,float _fcx,float _fcy) :
	fX(_fx), fY(_fy), fCX(_fcx), fCY(_fcy)
	{

	}
}INFO;

typedef struct tagFrame
{
	int nStart;
	int nLast;
	int nScene;
	DWORD dwTime;

	tagFrame(){}
	tagFrame(int _nstart, int _nlast, int _nscene, DWORD _dwtime) :
	nStart(_nstart), nLast(_nlast), nScene(_nscene), dwTime(_dwtime)
	{

	}

}FRAME;

//typedef struct tagShape
//{
//	const string strTextureName;
//	float fSize;
//	float fHit;
//}SHAPE;