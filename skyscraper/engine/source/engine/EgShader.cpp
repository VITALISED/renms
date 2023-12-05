/**
 * @file EgShader.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-05
 * 
 * Copyright (C) 2023  VITALISED & Contributors
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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