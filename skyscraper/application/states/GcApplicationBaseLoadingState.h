#pragma once

#include <skyscraper.h>

#include <application/states/GcApplicationState.h>
#include <toolkit/system/timer/TkTimer.h>

SKYSCRAPER_BEGIN

class cGcApplicationBaseLoadingState : public cGcApplicationState
{
  public:
    float mfDistractionFXAlphaOverride;
    bool mbShowDistractionFX;
    cTkTimerTemplate<0> mLoadingBackgroundFadeInTimer;
    cTkSmartResHandle mLoadingScreenBackgroundRes;
    bool mbTextureIsReady;

    virtual void Prepare(cTkFSMState *, void const *);
    virtual void Release(cTkFSMState *, void const *);
    virtual void Render(EgRenderParity::List);

    virtual void LoadingRender2D();
    virtual void LoadingRenderNVG();
};

SKYSCRAPER_END