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
#include <gamestate/basebuilding/BaseIndex.h>
#include <toolkit/simulation/TkSeed.h>
#include <metadata/utilities/data/gcresourceelement.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerNPCWorkers
{
    struct WorkerStationInfo
    {
        bool mbWorkerHired;
        BaseIndex muWorkerIndex;
        cGcResourceElement mWorkerResourceData;
        cTkSeed mNPCInteractionSeed;
    };
};

SKYSCRAPER_END