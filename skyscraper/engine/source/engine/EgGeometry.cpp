/**
 * @file EgGeometry.cpp
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