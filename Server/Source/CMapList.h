#pragma once
#include "CSingleton.h"

#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>

class CMapList : public CSingleton<CMapList>
{
public:
	static constexpr const char* s_MapList[] = {
		"d1_trainstation_01",
		"d1_trainstation_02",
		"d1_trainstation_03",
		"d1_trainstation_04",
		"d1_trainstation_05",
		"d1_trainstation_06",
		"d1_canals_01",
		"d1_canals_01a",
		"d1_canals_02",
		"d1_canals_03",
		"d1_canals_05",
		"d1_canals_06",
		"d1_canals_07",
		"d1_canals_08",
		"d1_canals_09",
		"d1_canals_10",
		"d1_canals_11",
		"d1_canals_12",
		"d1_canals_13",
		"d1_eli_01",
		"d1_eli_02",
		"d1_town_01",
		"d1_town_01a",
		"d1_town_02",
		"d1_town_03",
		"d1_town_02a",
		"d1_town_04",
		"d1_town_05",
		"d2_coast_01",
		"d2_coast_03",
		"d2_coast_04",
		"d2_coast_05",
		"d2_coast_07",
		"d2_coast_08",
		"d2_coast_09",
		"d2_coast_10",
		"d2_coast_11",
		"d2_coast_12",
		"d2_prison_01",
		"d2_prison_02",
		"d2_prison_03",
		"d2_prison_04",
		"d2_prison_05",
		"d2_prison_06",
		"d2_prison_07",
		"d2_prison_08",
		"d3_c17_01",
		"d3_c17_02",
		"d3_c17_03",
		"d3_c17_04",
		"d3_c17_05",
		"d3_c17_06a",
		"d3_c17_06b",
		"d3_c17_07",
		"d3_c17_08",
		"d3_c17_09",
		"d3_c17_10a",
		"d3_c17_10b",
		"d3_c17_11",
		"d3_c17_12",
		"d3_c17_12b",
		"d3_c17_13",
		"d3_citadel_01",
		"d3_citadel_02",
		"d3_citadel_03",
		"d3_citadel_04",
		"d3_citadel_05",
		"d3_breen_01",
		"final"
	};

	static constexpr size_t NUM_MAPS = sizeof(s_MapList) / sizeof(*s_MapList);

public:
	static constexpr uint8_t INVALID_MAP = -1;

public:
	CMapList()
	{
		for (size_t i = 0; i < NUM_MAPS; i++)
			AddMap(s_MapList[i]);
	}

	uint8_t GetMapIndex(const std::string_view& mapName) const
	{
		auto it = std::find(m_OrderedMapNameHashes.begin(), m_OrderedMapNameHashes.end(), GetHash(mapName));

		if (it != m_OrderedMapNameHashes.end())
			return static_cast<uint8_t>(std::distance(m_OrderedMapNameHashes.begin(), it));

		return INVALID_MAP;
	}

private:
	static size_t GetHash(const std::string_view& mapName)
	{
		static std::hash<std::string_view> s_Hasher;
		return s_Hasher(mapName);
	}

	void AddMap(const std::string_view& mapName)
	{
		m_OrderedMapNameHashes.push_back(
			GetHash(mapName)
		);
	}

private:
	std::vector<size_t> m_OrderedMapNameHashes;
};