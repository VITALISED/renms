#include <engine/source/engine/EgTexture.h>

SKYSCRAPER_BEGIN

cEgTextureResource::~cEgTextureResource()
{
    EMPTY_CALL_DESTRUCTOR();
}

int32_t cEgTextureResource::GetDataSize()
{
    EMPTY_CALL();
}

void cEgTextureResource::Release()
{
    EMPTY_CALL_VOID();
}

void cEgTextureResource::InitDefault()
{
    EMPTY_CALL_VOID();
}

bool cEgTextureResource::Load(const char *, int)
{
    EMPTY_CALL();
}

int32_t cEgTextureResource::GetElementCount(int)
{
    EMPTY_CALL();
}

int32_t cEgTextureResource::GetElementParamInt(int, int, int)
{
    EMPTY_CALL();
}

void cEgTextureResource::SetElementParamInt(int, int, int, int)
{
    EMPTY_CALL_VOID();
}

float cEgTextureResource::GetElementParamFloat(int, int, int, int)
{
    EMPTY_CALL();
}

void cEgTextureResource::SetElementParamFloat(int, int, int, int, float)
{
    EMPTY_CALL_VOID();
}

void *cEgTextureResource::MapResStream(int, int, int, bool, bool, const char *)
{
    EMPTY_CALL();
}

void cEgTextureResource::UnmapStream(int)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END