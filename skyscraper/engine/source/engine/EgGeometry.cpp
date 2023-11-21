#include <engine/source/engine/EgGeometry.h>

SKYSCRAPER_BEGIN

cEgGeometryResource::~cEgGeometryResource()
{
    EMPTY_CALL_DESTRUCTOR();
}

cTkResource *cEgGeometryResource::Clone()
{
    EMPTY_CALL();
}

void cEgGeometryResource::CloneInternal(const cTkResource *)
{
    EMPTY_CALL_VOID();
}

void cEgGeometryResource::Release()
{
    EMPTY_CALL_VOID();
}

void cEgGeometryResource::InitDefault()
{
    EMPTY_CALL_VOID();
}

bool cEgGeometryResource::Load(const char *, int)
{
    EMPTY_CALL();
}

int cEgGeometryResource::GetElementCount(int)
{
    EMPTY_CALL();
}

int cEgGeometryResource::GetElementParamInt(int, int, int)
{
    EMPTY_CALL();
}

void cEgGeometryResource::SetElementParamInt(int, int, int, int)
{
    EMPTY_CALL_VOID();
}

void *cEgGeometryResource::MapResStream(int, int, int, bool, bool, const char *)
{
    EMPTY_CALL();
}

SKYSCRAPER_END