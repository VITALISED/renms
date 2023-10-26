#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkMetaMessageMap.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

enum eBehaviourTreeState
{
	EBehaviourTree_Ready,
	EBehaviourTree_Running,
	EBehaviourTree_Success,
	EBehaviourTree_Failure,
	EBehaviourTree_Num = 4,
};

enum eBehaviourTreeNodeType
{
	EBehaviourTreeNodeType_SequenceSelector,
	EBehaviourTreeNodeType_PrioritySelector,
	EBehaviourTreeNodeType_ConcurrentSelector,
	EBehaviourTreeNodeType_StochasticSelector,
	EBehaviourTreeNodeType_InverseDecorator,
	EBehaviourTreeNodeType_SwitchDecorator,
	EBehaviourTreeNodeType_SelectionDecorator,
	EBehaviourTreeNodeType_SucceedOnSwitchDecorator,
	EBehaviourTreeNodeType_SucceedOnSelectionDecorator,
	EBehaviourTreeNodeType_AlwaysSucceedDecorator,
	EBehaviourTreeNodeType_AlwaysRunDecorator,
	EBehaviourTreeNodeType_NeverFailDecorator,
	EBehaviourTreeNodeType_LeafNode,
	EBehaviourTreeNodeType_NumTypes = 13,
};


class cTkBehaviourTreeNode
{
	eBehaviourTreeState meState;
	eBehaviourTreeNodeType meType;
	struct
	{
		__int8 mbRunning : 1;
		__int8 mbDebugBreak : 1;
		__int8 mbExpanded : 1;
		__int8 mbDebugDraw : 1;
	} mFlags;

	virtual ~cTkBehaviourTreeNode();
	eBehaviourTreeState Update(float);
	void Cancel();
	void Subscribe(cTkMetaMessageMap<2>*);
	void AddNode(cTkBehaviourTreeNode*);
	int GetNumChildren();
	cTkBehaviourTreeNode* GetChild(int);
	const char* GetName();
	void GetDescription(cTkFixedString<64, char>*);
	void ToggleDebugBreak();
	bool CanDebugBreak();
	bool IsDebugBreakSet();
	bool CanExpand();
	void NGuiRender();
};


SKYSCRAPER_END