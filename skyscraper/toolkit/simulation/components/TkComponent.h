/**
 * @file TkComponent.h
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

#include <toolkit/data/TkClassPointer.h>
#include <toolkit/networking/TkReplicatedVariableArray.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

class cTkAttachment;
class cGcNetworkSerializer;

class cTkComponent
{
  public:
    cTkAttachment *mpAttachment;
    const char *mpacType;
    cTkComponent *mpNext;
    int miTypeIndex;
    float mfUpdatePeriod;
    float mfUpdateDelta;
    bool mbIsPrepared;
    bool mbWantsNetSerialize;
    bool mbWantsNetSerializeOnInit;
    bool mbWantsUpdate;
    bool mbWantsUpdateOverride;
    bool mbIsLocalPlayerEntityOwner;
    bool mbIsLocalPlayerEntityOwnerDirty;
    cTkReplicatedVariableArray mapReplicatedVariables;

    virtual ~cTkComponent();
    virtual void Update(float);
    virtual void UpdatePostPhysics(float);
    virtual void UpdateRender(float);
    virtual void Render();
    virtual bool NetSerialize(cGcNetworkSerializer *, uint64_t);
    virtual bool NetSerializeOnInit(cGcNetworkSerializer *);
    virtual bool CanTransferOwnership();
    virtual bool AmInterestedInOwnership();
    virtual bool ShouldKeepAlive();
    virtual bool ShouldAbandon();
    virtual bool OnOwnershipTransfer(const cTkUserIdBase<cTkFixedString<64, char>> *);
    virtual void RenderNGui();
    virtual uint64_t GetTypeNameHash64();
    virtual void OnAttached();
    virtual void Prepare();
    virtual void Release();
    virtual void InitData(cTkClassPointer *);
    virtual void DefaultRenderNGui();
    virtual float GetUpdatePeriod();
};

class cTkComponentUpdater
{
  public:
    uint64_t miComponentsBufferBaseAddress;
    int miComponentsBufferStride;
    int miComponentsBufferElementCount;

    void OnInit(uint64_t, int, int);
    bool UpdateComponents(cTkComponent **, int16_t *, int, float);
    bool UpdateComponentsPostPhysics(cTkComponent **, int16_t *, int, float);
    bool UpdateComponentsRender(cTkComponent **, int16_t *, int, float);
    void OnComponentAllocate(cTkComponent *);
    void OnComponentFree(cTkComponent *);
    bool HasCustomUpdate();
};

SKYSCRAPER_END