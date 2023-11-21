#include <toolkit/resources/TkResource.h>

SKYSCRAPER_BEGIN

cTkResource::~cTkResource()
{
    EMPTY_CALL_DESTRUCTOR();
}

bool cTkResource::IsLoaded()
{
    EMPTY_CALL();
}

void cTkResource::SetDescriptor(const cTkResourceDescriptor *lpDescriptor)
{
    EMPTY_CALL_VOID();
}

void cTkResource::CloneInternal(const cTkResource *lpResource)
{
    EMPTY_CALL_VOID();
}

bool cTkResource::Equals(const char *lpacName, const cTkResourceDescriptor *lpDescriptor, int liType)
{
    EMPTY_CALL();
}

SKYSCRAPER_END