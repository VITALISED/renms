/**
 * @file dllmain.cpp
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

#include <renms.h>

#include <application/GcApplication.h>

using namespace nms;

void RENMS_ENTRY PluginMain()
{
    std::printf("Hello from the plugin!\n");
}

void RENMS_ENTRY PluginUpdate()
{
    cGcApplication *gApplication = reinterpret_cast<cGcApplication *>(GetModuleHandleA("NMS.exe") + GCAPPLICATION);

    if (gApplication->mpData->mSimulation.mPlayer.mbMoving)
    {
        std::printf(
            "%e, %e, %e\n", gApplication->mpData->mSimulation.mPlayer.mPosition[0],
            gApplication->mpData->mSimulation.mPlayer.mPosition[1],
            gApplication->mpData->mSimulation.mPlayer.mPosition[2]);
    }
}