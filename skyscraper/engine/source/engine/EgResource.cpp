/**
 * @file EgResource.cpp
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