#include "CPlayer.h"
#include "CLog.h"

void CPlayer::OnNetRegistered()
{
	m_eFlags |= Flags_Online;
}

void CPlayer::OnNetUnregistered()
{
	m_eFlags &= ~Flags_Online;
}

void CPlayer::ProceedNetworkData(void* pData)
{
	LOG_TRACE("CPlayer ({}) got new network data", m_uiSteamID);
}
