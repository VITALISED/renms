#pragma once

#include <skyscraper.h>

#include <engine/source/engine/EgShader.h>
#include <toolkit/system/TkIterationState.h>

SKYSCRAPER_BEGIN

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