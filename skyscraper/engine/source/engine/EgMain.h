#pragma once

#include <skyscraper.h>
#include <engine/source/engine/EgShader.h>
#include <toolkit/system/TkIterationState.h>
#include <toolkit/utilities/containers/TkStackVector.h>

SKYSCRAPER_BEGIN

namespace Engine
{
    struct cEgShaderCompilationState
    {
        cTkStackVector<cEgShaderResource::CombinationCompilationTask> mTasks;
        cTkStackVector<cEgShaderResource::CombinationCompilationTask> mPreloadTasks;
        TkIterationState<1> mContextIteration;
        TkIterationState<1> mTaskIteration;
        TkIterationState<1> mPreloadTaskIteration;
    };
}

SKYSCRAPER_END