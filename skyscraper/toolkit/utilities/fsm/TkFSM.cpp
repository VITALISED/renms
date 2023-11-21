#include <toolkit/utilities/fsm/TkFSM.h>

SKYSCRAPER_BEGIN

cTkFSM::~cTkFSM()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cTkFSM::Construct(const cTkFSMStateOffset *, const TkID<128> *)
{
    EMPTY_CALL_VOID();
}

void cTkFSM::Update(float)
{
    EMPTY_CALL_VOID();
}

void cTkFSM::Destruct()
{
    EMPTY_CALL_VOID();
}

void cTkFSM::StatePrepare(cTkFSMState *, const void *)
{
    EMPTY_CALL_VOID();
}

void cTkFSM::StateRelease(cTkFSMState *, const void *)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END