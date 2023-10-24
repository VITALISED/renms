#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

enum eCharacterPhysicsDisabledReasons
{
	ECharacterPhysicsDisabledReason_None,
	ECharacterPhysicsDisabledReason_MovementDisabled = (1 << 0),
	ECharacterPhysicsDisabledReason_Sitting = (1 << 1),
	ECharacterPhysicsDisabledReason_Riding = (1 << 2),
	ECharacterPhysicsDisabledReason_ClimbingLadder = (1 << 3),
	ECharacterPhysicsDisabledReason_NavFallback = (1 << 4),
	ECharacterPhysicsDisabledReason_Replicated = (1 << 5),
	ECharacterPhysicsDisabledReason_Any = (ECharacterPhysicsDisabledReason_MovementDisabled | ECharacterPhysicsDisabledReason_Sitting | ECharacterPhysicsDisabledReason_Riding | ECharacterPhysicsDisabledReason_ClimbingLadder | ECharacterPhysicsDisabledReason_NavFallback | ECharacterPhysicsDisabledReason_Replicated)
};

SKYSCRAPER_END