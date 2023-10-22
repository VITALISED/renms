#pragma once

#include <skyscraper.h>
#include <toolkit/networking/TkReplicatedVariableArray.h>

SKYSCRAPER_BEGIN

class cTkAttachment;

class cTkComponent
{
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
    virtual bool NetSerialize(cGcNetworkSerializer *, unsigned __int64);
    virtual bool NetSerializeOnInit(cGcNetworkSerializer *);
    virtual bool CanTransferOwnership();
    virtual bool AmInterestedInOwnership();
    virtual bool ShouldKeepAlive();
    virtual bool ShouldAbandon();
    virtual bool OnOwnershipTransfer(const cTkUserIdBase<cTkFixedString<64,char> > *);
    virtual void RenderNGui();
    virtual unsigned __int64 GetTypeNameHash64();
    virtual void OnAttached();
    virtual void Prepare();
    virtual void Release();
    virtual void InitData(cTkClassPointer *);
    virtual void DefaultRenderNGui();
    virtual float GetUpdatePeriod();
};


SKYSCRAPER_END