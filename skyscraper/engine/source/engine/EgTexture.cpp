/**
 * @file EgTexture.cpp
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