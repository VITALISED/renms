#pragma once

#include <skyscraper.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/utilities/fsm/TkFSMState.h>

SKYSCRAPER_BEGIN

class cTkFSM
{
    const cTkFSMStateOffset *mpOffsetTable;
    cTkFSMState *mpState;
    TkID<128> mRequestedChangeNewState;
    const void *mpRequestedChangeUserData;
    bool mbRequestedChangeForceRestart;

    virtual ~cTkFSM();
    virtual void Construct(const cTkFSMStateOffset *, const TkID<128> *);
    virtual void Update(float);
    virtual void Destruct();
    virtual void StatePrepare(cTkFSMState *, const void *);
    virtual void StateRelease(cTkFSMState *, const void *);
};

SKYSCRAPER_END