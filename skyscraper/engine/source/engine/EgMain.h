/**
 * @file EgMain.h
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

#include <engine/source/engine/EgShader.h>
#include <toolkit/system/TkIterationState.h>

SKYSCRAPER_BEGIN

struct EgRenderQueueHandle
{
    int miQueueId;
    int miFrameId;
};

enum EgRenderView
{
    __Normal,
    LeftEye,
    RightEye,
};

namespace EgRenderCullMode
{

enum Mode
{
    UpdateEverything_SyncCull,
    UpdateEverything_AsyncCull,
    UpdateEverything_SingleThreadCull,
    NoUpdates_SyncCull,
    NoUpdates_AsyncCull,
    NoUpdates_SingleThreadCull,
    UpdateNodesNotFlags_SyncCull,
    UpdateNodesNotFlags_AsyncCull,
    UpdateNodesNotFlags_SingleThreadCull,
    PassDoesNotUseNodeGraph,
    UpdateEverything_DrawAllEnabled,
    NoUpdates_DrawAllEnabled,
    UpdateNodesNotFlags_DrawAllEnabled,
};

} // namespace EgRenderCullMode

namespace Engine
{

class cEgShaderCompilationState
{
  public:
    cTkStackVector<cEgShaderResource::CombinationCompilationTask, 64> mTasks;
    cTkStackVector<cEgShaderResource::CombinationCompilationTask, 64> mPreloadTasks;
    TkIterationState<1> mContextIteration;
    TkIterationState<1> mTaskIteration;
    TkIterationState<1> mPreloadTaskIteration;
};

} // namespace Engine

SKYSCRAPER_END