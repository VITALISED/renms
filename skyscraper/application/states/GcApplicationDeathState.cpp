#include <application/states/GcApplicationDeathState.h>

SKYSCRAPER_BEGIN

cGcApplicationDeathState::~cGcApplicationDeathState()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cGcApplicationDeathState::Construct()
{
    EMPTY_CALL_VOID();
}

void cGcApplicationDeathState::Prepare(cTkFSMState *, const void *)
{
    EMPTY_CALL_VOID();
}

void cGcApplicationDeathState::Update(float)
{
    EMPTY_CALL_VOID();
}

void cGcApplicationDeathState::Release(cTkFSMState *, const void *)
{
    EMPTY_CALL_VOID();
}

void cGcApplicationDeathState::Render(EgRenderParity::List)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END