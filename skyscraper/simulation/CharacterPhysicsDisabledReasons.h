/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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