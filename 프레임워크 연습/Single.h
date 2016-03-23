#pragma once

#include "Include.h"

template <typename T>
class CSingle
{
private:
	static T*	m_pInst;

public:
	static inline T* GetInst(void)
	{
		if(!m_pInst)
			m_pInst = new T;

		return m_pInst;
	}

	void DestoryInst(void)
	{
		delete m_pInst;
		m_pInst = NULL;
	}

protected:
	CSingle(void)	{};

public:
	~CSingle(void)	{};
};


template <typename T>
T*	CSingle<T>::m_pInst = NULL;