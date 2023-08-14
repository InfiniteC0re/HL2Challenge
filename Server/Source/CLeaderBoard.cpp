#include "CLeaderBoard.h"
#include <stdio.h>

void CLeaderBoard::Sort()
{
	// TODO: create the method
}

void CLeaderBoard::DumpToFile() const
{
	FILE* pFile = fopen(ms_szDumpFilePath, "wb");

	size_t uiNumPlayers = GetNumOfPlayers();
	fwrite(&uiNumPlayers, sizeof(uiNumPlayers), 1, pFile);
	fwrite(m_PlayerList.data(), sizeof(CPlayer), uiNumPlayers, pFile);

	fclose(pFile);
}

void CLeaderBoard::UndumpFromFile()
{
	// TODO: create the method
}
