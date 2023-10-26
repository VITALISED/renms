#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/animation/engine/TkNodeAnimationControllerEngine.h>
#include <toolkit/utilities/containers/TkStackVector.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>
#include <metadata/components/animation/tkanimationcomponentdata.meta.h>
#include <metadata/enginesettings/tkanimdetailsettings.meta.h>

SKYSCRAPER_BEGIN

class cTkAnimationComponent : public cTkComponent
{
	struct AnimSnapshot
	{
		cTkStackVector<cTkAnimCommand> lBuffer;
		unsigned __int64 luTime;
	};

	cTkAnimationComponentData* mpData;
	std::vector<cTkAnimCommand> mRemoteCommandBuffer;
	std::deque<cTkAnimationComponent::AnimSnapshot> mAnimSnapshots;
	cTkLinearHashTable<TkID<128>, int, cTkLinearHashTableHash<TkID<128> > > mAnimIdToIndexLookup;
	cTkNodeAnimationController mAnimationController;
	TkHandle mModelNode;
	bool mbAnimationLoaded;
	bool mbAnimationPrepared;
	bool mbBreakOnUpdate;
	bool mbIsModelViewerNode;
	bool mbDistanceCulled;
	eCreatureSize meCreatureSize;
	__int16* mpAnimMappingsReverseLookup;
	cTkAnimDetailSettings* mpaDetailLevels;
	bool mbEverUpdated;
	unsigned int muAnimCullFrameMarker;
	float mfTimeSinceLastUpdateRecvd;
	cTkMatrix34 mRootMotionBuffer;
	bool mbRecordRootMotion;
	bool mDisableAnimation;
	bool mbShowAnimMirrorPairs;
};

SKYSCRAPER_END