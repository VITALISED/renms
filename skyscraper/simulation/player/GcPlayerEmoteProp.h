#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <metadata/source/simulation/player/gcplayeremotepropdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerEmoteProp
{
public:
	enum eState
	{
		Inactive,
		LoadingResource,
		Visible,
	};

	cGcPlayerEmoteProp::eState meState;
	const cGcPlayerEmotePropData* mpData;
	cTkSmartResHandle mModelResource;
	TkHandle mNode;
	TkHandle mAttachNode;
	cTkAttachmentPtr mpPlayerAttachment;
	cTkSmoothCD<float> mCurrentScale;
	float mfConstructTime;
	bool mbRequestedRemove;
	TkHandle mLightNode;
	TkHandle mScanEffectNode;
	float mfDefaultLightIntensity;
};

SKYSCRAPER_END