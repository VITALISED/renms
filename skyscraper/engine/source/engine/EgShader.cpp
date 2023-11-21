#include <engine/source/engine/EgShader.h>

SKYSCRAPER_BEGIN

cEgCodeResource::~cEgCodeResource()
{
    EMPTY_CALL_DESTRUCTOR();
}

cTkResource *cEgCodeResource::Clone()
{
    EMPTY_CALL();
}

void cEgCodeResource::CloneInternal(const cTkResource *)
{
    EMPTY_CALL_VOID();
}

void cEgCodeResource::Release()
{
    EMPTY_CALL_VOID();
}

void cEgCodeResource::InitDefault()
{
    EMPTY_CALL_VOID();
}

bool cEgCodeResource::Load(const char *, int)
{
    EMPTY_CALL();
}

cEgShaderResource::~cEgShaderResource()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cEgShaderResource::Release()
{
    EMPTY_CALL_VOID();
}

bool cEgShaderResource::Load(const char *, int)
{
    EMPTY_CALL();
}

int cEgShaderResource::GetElementCount(int)
{
    EMPTY_CALL();
}

float cEgShaderResource::GetElementParamFloat(int, int, int, int)
{
    EMPTY_CALL();
}

void cEgShaderResource::SetElementParamFloat(int, int, int, int, float)
{
    EMPTY_CALL_VOID();
}

const char *cEgShaderResource::GetElementParamStr(int, int, int)
{
    EMPTY_CALL();
}

void cEgShaderResource::SetElementParamStr(int, int, int, const char *)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END