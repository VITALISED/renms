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
#include <simulation/components/utils/GcPlayerCharacterComponent.h>
#include <toolkit/simulation/TkBlackBoard.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/simulation/components/TkSketchComponent.h>
#include <toolkit/simulation/physics/havok/TkHavokDynamicCharacterController.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/simulation/components/utils/gcplayercontrolcomponentdata.meta.h>
#include <metadata/simulation/character/inputclasses/gcplayercontrolinputremap.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerControlComponent : public cTkComponent
{
	class cGcCachedSketchVariable
	{
		TkID<128> mName;
		float mfValue;
	};

	cGcPlayerControlComponentData* mpData;
	cTkSketchComponent* mpSketch;
	cTkHavokCharacterController* mpPhysicsController;
	cGcPlayerCharacterComponent* mpCharacter;
	TkID<128> mCurrentState;
	TkID<128> mRequestedState;
	cTkVector2 mMousePos;
	cTkVector3 mvMoveDir;
	cTkVector<cGcPlayerControlComponent::cGcCachedSketchVariable> maCachedVariables;
	bool mbInputsChanged;
	bool mbUpdatingInputs;
	cTkVector<cGcPlayerControlInputRemap const*> maRemappedInputs;
	cTkBlackboard mBlackboard;
};

SKYSCRAPER_END