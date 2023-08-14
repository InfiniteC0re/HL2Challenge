#include "IReplicable.h"

bool IReplicable::IsValidNetObject(NetObjectId objectId)
{
	return m_NetObject == objectId;
}