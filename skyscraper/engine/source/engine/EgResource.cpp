#include <engine/source/engine/EgResource.h>

SKYSCRAPER_BEGIN

void cEgResource::CloneInternal(const cTkResource *)
{
    EMPTY_CALL_VOID();
}

bool cEgResource::Load(const char *, int)
{
    EMPTY_CALL();
}

int cEgResource::GetElementCount(int)
{
    EMPTY_CALL();
}

int cEgResource::GetElementParamInt(int, int, int)
{
    EMPTY_CALL();
}

void cEgResource::SetElementParamInt(int, int, int, int)
{
    EMPTY_CALL_VOID();
}

float cEgResource::GetElementParamFloat(int, int, int, int)
{
    EMPTY_CALL();
}

void cEgResource::SetElementParamFloat(int, int, int, int, float)
{
    EMPTY_CALL_VOID();
}

const char *cEgResource::GetElementParamStr(int, int, int)
{
    EMPTY_CALL();
}

void cEgResource::SetElementParamStr(int, int, int, const char *)
{
    EMPTY_CALL_VOID();
}

void *cEgResource::MapResStream(int, int, TkHandle, bool, bool, const char *)
{
    EMPTY_CALL();
}

void *cEgResource::MapResStream(int, int, int, bool, bool, const char *)
{
    EMPTY_CALL();
}

void cEgResource::UnmapStream(TkHandle, bool)
{
    EMPTY_CALL_VOID();
}

void cEgResource::UnmapStream(int)
{
    EMPTY_CALL_VOID();
}

cTkAABB *cEgResource::GetBoundingBox(cTkAABB *result)
{
    EMPTY_CALL();
}

SKYSCRAPER_END