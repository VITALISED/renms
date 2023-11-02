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

#include "heridium.h"
#include "cpp/lang.h"
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/data/TkMetaDataXML.h>
#include <memory/hooks.h>


using namespace nms;

void AnalysisInit();

HERIDIUM_BEGIN

//void DoLookupIter();
//HACK: since I lack the braincells to figure out how hashes are generated we will instead retrieve them from the generated functions.
uintptr_t UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction);

HERIDIUM_END