/**
 * @file TkBehaviourTreeNode.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <toolkit/utilities/containers/TkMetaMessageMap.h>
#include <toolkit/utilities/string/TkString.h>

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
  public:
    eBehaviourTreeState meState;
    eBehaviourTreeNodeType meType;
    struct
    {
        int8_t mbRunning : 1;
        int8_t mbDebugBreak : 1;
        int8_t mbExpanded : 1;
        int8_t mbDebugDraw : 1;
    } mFlags;

    virtual ~cTkBehaviourTreeNode();
    virtual eBehaviourTreeState Update(float);
    virtual void Cancel();
    virtual void Subscribe(cTkMetaMessageMap<2> *);
    virtual void AddNode(cTkBehaviourTreeNode *);
    virtual int GetNumChildren();
    virtual cTkBehaviourTreeNode *GetChild(int);
    virtual const char *GetName();
    virtual void GetDescription(cTkFixedString<64, char> *);
    virtual void ToggleDebugBreak();
    virtual bool CanDebugBreak();
    virtual bool IsDebugBreakSet();
    virtual bool CanExpand();
    virtual void NGuiRender();
};

SKYSCRAPER_END