#pragma once
#include "CPlayer.h"
#include "CSingleton.h"

#include <vector>

class CLeaderBoard : public CSingleton<CLeaderBoard>
{
public:
	CLeaderBoard()
	{
		m_PlayerList.reserve(128);
		UndumpFromFile();
	}

	~CLeaderBoard()
	{
		for (auto pPlayer : m_PlayerList)
			delete pPlayer;
	}

	void Sort();

	void DumpToFile() const;
	void UndumpFromFile();

	CPlayer* CreatePlayer()
	{
		return nullptr;
	}

	CPlayer* FindPlayerBySteamId(uint64_t uiSteamId) const
	{
		for (auto pPlayer : m_PlayerList)
		{
			if (pPlayer->GetSteamID() == uiSteamId)
				return pPlayer;
		}

		return nullptr;
	}

	CPlayer* FindPlayerByNetId(NetObjectId netObjectId) const
	{
		for (auto pPlayer : m_PlayerList)
		{
			if (pPlayer->GetNetObjectId() == netObjectId)
				return pPlayer;
		}

		return nullptr;
	}

	size_t GetNumOfPlayers() const
	{
		return m_PlayerList.size();
	}

	std::vector<CPlayer*>::iterator begin()
	{
		return m_PlayerList.begin();
	}

	std::vector<CPlayer*>::iterator end()
	{
		return m_PlayerList.end();
	}

	std::vector<CPlayer*>::const_iterator cbegin()
	{
		return m_PlayerList.cbegin();
	}

	std::vector<CPlayer*>::const_iterator cend()
	{
		return m_PlayerList.cend();
	}

private:
	static constexpr const char* ms_szDumpFilePath = "Saves\\CLeaderBoard";

private:
	std::vector<CPlayer*> m_PlayerList;
};
