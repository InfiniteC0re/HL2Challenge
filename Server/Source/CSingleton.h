#pragma once
#include "CLog.h"

template <class T>
class CSingleton
{
public:
	template <typename ... Args>
	static T* CreateSingleton(Args&&... args)
	{
		return new T(std::forward<Args>(args)...);
	}

	static void DestroySingleton()
	{
		ASSERT(ms_pSingleton != nullptr);
		delete ms_pSingleton;
	}

	static T* GetSingleton()
	{
		ASSERT(ms_pSingleton != nullptr);
		return ms_pSingleton;
	}

protected:
	CSingleton()
	{
		ASSERT(ms_pSingleton == nullptr);
		ms_pSingleton = static_cast<T*>(this);
	}

	~CSingleton()
	{
		ms_pSingleton = nullptr;
	}

protected:
	inline static T* ms_pSingleton = nullptr;
};