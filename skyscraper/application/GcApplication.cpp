#include <application/GcApplication.h>

SKYSCRAPER_BEGIN

cGcApplication::~cGcApplication()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cGcApplication::Construct()
{
    EMPTY_CALL_VOID();
}

void cGcApplication::Update()
{
    EMPTY_CALL_VOID();
}

void cGcApplication::Destruct()
{
    EMPTY_CALL_VOID();
}

void cGcApplication::StatePrepare(cTkFSMState *, const void *)
{
    EMPTY_CALL_VOID();
}

void cGcApplication::StateRelease(cTkFSMState *, const void *)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END