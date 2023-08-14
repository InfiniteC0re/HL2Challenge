#pragma once
#include "CLog.h"
#include "CStack.h"

#include <cstdint>
#include <array>

using NetObjectId = uint32_t;

class IReplicable
{
public:
	static constexpr NetObjectId INVALID_OBJECT = 0;

public:
	IReplicable()
	{
		m_NetObject = INVALID_OBJECT;
	}

	NetObjectId GetNetObjectId() const
	{
		return m_NetObject;
	}

	NetObjectId NetRegister()
	{
		ASSERT(m_NetObject == INVALID_OBJECT);
		m_NetObject = ms_FreeNetworkObjects.Pop();
		NetSetUserData(nullptr);
		OnNetRegistered();

		return m_NetObject;
	}

	NetObjectId NetUnregister()
	{
		ASSERT(m_NetObject != INVALID_OBJECT);
		ms_FreeNetworkObjects.Push(m_NetObject);
		NetSetUserData(nullptr);
		OnNetUnregistered();

		return std::exchange(m_NetObject, INVALID_OBJECT);
	}

	template <class T>
	T* NetGetUserData() const
	{
		ASSERT(m_NetObject != INVALID_OBJECT);
		return static_cast<T*>(ms_NetworkObjectsUserData[m_NetObject]);
	}

	void NetSetUserData(void* pData)
	{
		ASSERT(m_NetObject != INVALID_OBJECT);
		ms_NetworkObjectsUserData[m_NetObject] = pData;
	}

	bool NetIsRegistered() const
	{
		return m_NetObject != INVALID_OBJECT;
	}

	virtual bool IsValidNetObject(NetObjectId objectId);
	virtual void ProceedNetworkData(void* pData) = 0;
	virtual void OnNetRegistered() { }
	virtual void OnNetUnregistered() { }

public:
	static void InitialiseStatic()
	{
		ms_FreeNetworkObjects.Create(MAX_NETWORK_OBJECTS_NUM);

		for (NetObjectId i = INVALID_OBJECT + 1; i <= MAX_NETWORK_OBJECTS_NUM; i++)
		{
			ms_FreeNetworkObjects.Push(MAX_NETWORK_OBJECTS_NUM - i + 1);
		}
	}

private:
	static constexpr NetObjectId MAX_NETWORK_OBJECTS_NUM = 2048;
	inline static CStack<NetObjectId> ms_FreeNetworkObjects;
	inline static std::array<void*, MAX_NETWORK_OBJECTS_NUM + 1> ms_NetworkObjectsUserData;

protected:
	NetObjectId m_NetObject;
};
