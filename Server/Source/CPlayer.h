#pragma once
#include "IReplicable.h"
#include "CMapList.h"
#include <cstdint>

class CPlayer : public IReplicable
{
public:
	using Flags = uint8_t;
	enum Flags_ : Flags
	{
		Flags_None     = 0,
		Flags_Online   = 1u << 0,
		Flags_Finished = 1u << 1,
	};

public:
	CPlayer() = default;
	~CPlayer() = default;

	const uint64_t GetSteamID() const { return m_uiSteamID; }
	const wchar_t* GetName() const { return m_szPlayerName; }
	float GetCompletedPercent() const { return m_fCompletePercent; }
	uint32_t GetNumDeaths() const { return m_uiDeathCount; }
	bool IsOnline() const { return m_eFlags & Flags_Online; }
	bool HasFinished() const { return m_eFlags & Flags_Finished; }
	uint8_t GetHealth() const { return m_uiHealth; }
	uint8_t GetCurrentMap() const { return m_uiCurrentMap; }

	virtual void OnNetRegistered() override;
	virtual void OnNetUnregistered() override;
	virtual void ProceedNetworkData(void* pData) override;

private:
	uint64_t m_uiSteamID = 0;
	wchar_t m_szPlayerName[64] = { L'\0' };
	float m_fCompletePercent = 0;
	uint32_t m_uiDeathCount = 0;
	Flags m_eFlags = Flags_None;
	uint8_t m_uiHealth = 100;
	uint8_t m_uiCurrentMap = CMapList::INVALID_MAP;
};
