#include "CLog.h"
#include "CPlayer.h"
#include "CMapList.h"
#include "CLeaderBoard.h"

int main()
{
	CLog::Create();
	IReplicable::InitialiseStatic();
	CMapList::CreateSingleton();
	CLeaderBoard::CreateSingleton();

	int iMapIndex = CMapList::GetSingleton()->GetMapIndex("d1_trainstation_03");
	float fProgress = (static_cast<float>(iMapIndex) / static_cast<float>(CMapList::NUM_MAPS)) * 100.0f;

	LOG_INFO("Current progress: {0}", fProgress);
}