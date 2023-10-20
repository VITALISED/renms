#pragma once

#include <skyscraper.h>
#include <engine/source/engine/EgRenderer.h>
#include <toolkit/data/TkMetaData.h>

SKYSCRAPER_BEGIN

class cTkFSM;

class cTkFSMStateOffset
{
    TkID<128> mID;
    unsigned __int64 mnOffset;
};

class cTkFSMState
{
    TkID<128> mID;
    cTkFSM *mpFSM;
    unsigned __int64 mu64StateTimingStart;

    virtual ~cTkFSMState();
    virtual void Construct();
    virtual void Prepare(cTkFSMState *, const void *);
    virtual void Update(float);
    virtual void Event(unsigned int, const void *);
    virtual void Release(cTkFSMState *, const void *);
    virtual void Destruct();
    virtual void Render(EgRenderParity::List);
    virtual bool SupportsEvenOddRendering();
};

SKYSCRAPER_END