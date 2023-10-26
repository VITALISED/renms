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