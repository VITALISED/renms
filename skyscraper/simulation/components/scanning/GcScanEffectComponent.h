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

#include <skyscraper.h>
#include <toolkit/networking/TkReplicatedVariable.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <metadata/source/simulation/components/scanning/gcscaneffectcomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcScanEffectComponent : cTkComponent
{
	cGcScanEffectComponentData* mpData;
	TkHandle mModelNode;
	cTkReplicatedVariable<int> miCurrentEffectIndex;
	int miPreviousEffectIndex;
};

SKYSCRAPER_END