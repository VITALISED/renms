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
#include <toolkit/attachments/TkHandle.h>
#include <string>

SKYSCRAPER_BEGIN

struct EgRenderQueueHandle
{
    int miQueueId;
    int miFrameId;
};

class cEgNodeAttachment
{
    TkHandle mNode;
    
    virtual ~cEgNodeAttachment();
    virtual void OnUpdate();
};

class cEgSceneNode
{
    cEgSceneNode_vtbl *__vftable /*VFT*/;
    TkHandle mLookupHandle;
    unsigned int muNameHash;
    cTkSmartResHandle mResHandle;
    unsigned int muNetworkId;
    cTkSharedPtr<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > msName;
    cTkSharedPtr<cTkResourceDescriptor const > mpAltId;
    cEgNodeAttachment *mpNodeAttachment;
    cTkSlotAlloc *mpAllocator;
    int miIsMaster;
};

class cEgSceneNodeTemplate
{
    cEgSceneNodeTemplate_vtbl *__vftable;
    __declspec(align(16)) int miType;
    unsigned int muNameHash;
    cTkSharedPtr<std::string> msName;
    cTkSharedPtr<cTkResourceDescriptor const > mpDescriptor;
    cTkVector3 mTranslation;
    cTkVector3 mRotation;
    cTkVector3 mScale;
    cTkAttachmentData *mpAttachment;
    cEgSceneNode *mpParent;
    TkHandle mHandle;
    std::vector<cEgSceneNodeTemplate *,TkSTLAllocatorShim<cEgSceneNodeTemplate *,8,-1> > mChildren;
};

SKYSCRAPER_END