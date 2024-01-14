/**
 * @file GcApplicationGlobalLoadState.h
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

#pragma once

#include <skyscraper.h>

#include <application/states/GcApplicationBaseLoadingState.h>
#include <atlas/WinHttpTask.h>

SKYSCRAPER_BEGIN

struct GlobalLoadPhase
{
    enum Enum
    {
        SetupGalaxyMapPreload,
        SetupGalaxyMap,
        FrontendPreload,
        TaskGenerationPhase1,
        TaskGenerationPhase2,
        CompleteMapGeneration,
        Complete,
        __EnumTerminator,
        Unspecified,
    };
};

class cGcApplicationGlobalLoadState : public cGcApplicationBaseLoadingState
{
  public:
    virtual ~cGcApplicationGlobalLoadState();
    virtual void Prepare(cTkFSMState *, const void *);
    virtual void Update(float);
    virtual void Release(cTkFSMState *, const void *);

    cGcAsyncLoadOps mAsyncLoadOps;
    GlobalLoadPhase::Enum mPhase;
};

SKYSCRAPER_END