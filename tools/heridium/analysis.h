/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include "cpp/lang.h"
#include "heridium.h"
#include "paths.h"
#include <filesystem>
#include <memory/hook.h>
#include <memory/thread.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/data/TkMetaDataXML.h>
#include <toolkit/utilities/containers/TkVector.h>

void cTkMetaData__Register__DETOUR(
    const cTkMetaDataClass *lpClassMetadata, void (*lDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *),
    void (*lFixingFunction)(cTkClassPointer *, bool, unsigned __int64), void (*lValidateFunction)(cTkClassPointer *),
    bool (*lEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *),
    void (*lRenderFunction)(cTkClassPointer *), void (*lCopyFunction)(cTkClassPointer *, const cTkClassPointer *),
    cTkClassPointer *(*lCreateFunction)(cTkClassPointer *result),
    unsigned __int64 (*lHashFunction)(const cTkClassPointer *, unsigned __int64, bool),
    void (*lDestroyFunction)(cTkClassPointer *));

HERIDIUM_BEGIN

using namespace nms;

void AnalysisInit();

HERIDIUM_END