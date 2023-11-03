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