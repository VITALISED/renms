#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/ai/behaviourtree/TkBehaviourTreeSelector.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/utilities/containers/TkMetaMessageMap.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cTkBehaviourTree
{
	TkHandle mSceneGraphNode;
	cTkBehaviourTreeSelector* mpRootNode;
	cTkMetaMessageMap<2> mMetaMessageSubscriptions;
	cTkVector<cTkBehaviourTreeNode*> mNodes;

	virtual ~cTkBehaviourTree();
	virtual void Construct(TkHandle);
	virtual void Construct(cTkAttachment*);
	virtual void Prepare();
	virtual void Update(float);
	virtual void Release();
	virtual void Destruct();
	virtual void RenderNGui();
	virtual char* GetErrorString(cTkBehaviourTreeNode*);
};

SKYSCRAPER_END