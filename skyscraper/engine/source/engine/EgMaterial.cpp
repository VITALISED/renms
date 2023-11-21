#include <engine/source/engine/EgMaterial.h>

SKYSCRAPER_BEGIN

cEgMaterialResource::~cEgMaterialResource()
{
    EMPTY_CALL_DESTRUCTOR();
}

bool cEgMaterialResource::OnResourceLoaded()
{
    EMPTY_CALL();
}

cTkResource *cEgMaterialResource::Clone()
{
    EMPTY_CALL();
}

void cEgMaterialResource::CloneInternal(const cTkResource *)
{
    EMPTY_CALL_VOID();
}

void cEgMaterialResource::Release()
{
    EMPTY_CALL_VOID();
}

void cEgMaterialResource::InitDefault()
{
    EMPTY_CALL_VOID();
}

bool cEgMaterialResource::Load(const char *, int)
{
    EMPTY_CALL();
}

int cEgMaterialResource::GetElementCount(int)
{
    EMPTY_CALL();
}

int cEgMaterialResource::GetElementParamInt(int, int, int)
{
    EMPTY_CALL();
}

void cEgMaterialResource::SetElementParamInt(int, int, int, int)
{
    EMPTY_CALL_VOID();
}

float cEgMaterialResource::GetElementParamFloat(int, int, int, int)
{
    EMPTY_CALL();
}

void cEgMaterialResource::SetElementParamFloat(int, int, int, int, float)
{
    EMPTY_CALL_VOID();
}

const char *cEgMaterialResource::GetElementParamStr(int, int, int)
{
    EMPTY_CALL();
}

void cEgMaterialResource::SetElementParamStr(int, int, int, const char *)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END