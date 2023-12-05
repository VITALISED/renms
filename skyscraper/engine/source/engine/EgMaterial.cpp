/**
 * @file EgMaterial.cpp
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