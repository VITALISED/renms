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

// #include <renms.h>

#include <application/GcApplication.h>
#include <sdk/core.h>
#include <spdlog/spdlog.h>

using namespace nms;

RENMS_ENTRY void PluginMain()
{
    spdlog::info("Hello from the plugin!\n");
}

RENMS_ENTRY void PluginUpdate()
{
    cGcApplication *gApplication = renms_sdk::GetApplication();

    if (gApplication->mpData->mSimulation.mPlayer.mbMoving)
    {
        float lookX, lookY, lookZ;
        cTkMatrix34 lPlayerTM = gApplication->mpData->mSimulation.mEnvironment.mPlayerEnvironment.mPlayerTM;

        lookX = atan2(lPlayerTM.mAt[1], lPlayerTM.mAt[2]);
        lookY =
            atan2(-lPlayerTM.mAt[0], sqrt(lPlayerTM.mAt[1] * lPlayerTM.mAt[1] + lPlayerTM.mAt[2] * lPlayerTM.mAt[2]));
        lookZ = atan2(lPlayerTM.mUp[0], lPlayerTM.mRight[0]);

        lookX = lookX * (180.0 / 3.141592653589793238463);
        lookY = lookY * (180.0 / 3.141592653589793238463);
        lookZ = lookZ * (180.0 / 3.141592653589793238463);

        // spdlog::info("Look Angles {} {} {}", lookX, lookY, lookZ);
    }
}