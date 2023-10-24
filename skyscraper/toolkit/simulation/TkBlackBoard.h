#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <metadata/simulation/tkblackboardcategory.meta.h>
#include <metadata/simulation/tkblackboardtype.meta.h>

SKYSCRAPER_BEGIN

class cTkBlackboardValue
{
	eBlackboardType meType;
	union
	{
		float mFloat;
		int miInteger;
		bool mBool;
		cTkVector3 mVector;
		cTkAttachmentPtr mpAttachment;
		TkID<128> mId;
	};
};

class cTkBlackboard
{
	eBlackboardCategory meCategory;
	cTkUnorderedMap<TkID<128>, cTkBlackboardValue, TkIDUnorderedMap::Hash128> maValues;
};

SKYSCRAPER_END