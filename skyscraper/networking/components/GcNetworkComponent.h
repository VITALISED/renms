#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkStackVector.h>

SKYSCRAPER_BEGIN

class cGcNetworkComponent : public cTkComponent
{
	struct sSurvey
	{
		unsigned __int8* mpResponses;
		unsigned __int16 maResponseBytes[31];
		unsigned __int16 muResponses;
		unsigned __int16 muRespondents;
		unsigned __int16 mSurveyHandle;
		float mfStartTime;
	};

	cTkStackVector<cGcNetworkComponent::sSurvey> mSurveys;
	unsigned __int16 muSurveyIndexer;
};

SKYSCRAPER_END