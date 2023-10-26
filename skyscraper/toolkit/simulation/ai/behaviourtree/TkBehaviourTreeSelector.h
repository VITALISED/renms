#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/ai/behaviourtree/TkBehaviourTreeNode.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cTkBehaviourTreeSelector : public cTkBehaviourTreeNode
{
	TkID<128> mHandle;
	cTkVector<cTkBehaviourTreeNode*> mChildren;
	int miNextChildToUpdate;
	bool mbDisable;
};

SKYSCRAPER_END