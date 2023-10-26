#pragma once

#include <skyscraper.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <metadata/source/simulation/solarsystem/planet/gcplanetweathercolourdata.meta.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

class cGcPresetDualPMap
{
    cTkSmartResHandle mFront;
    cTkSmartResHandle mBack;
    TkStrongType<int,TkStrongTypeIDs::cTkNGuiFontHandleID> mPreview;
    cGcPlanetWeatherColourData mWeather;
    float mfIntensity;
    cTkVector3 mLightDirection;
    cTkFixedString<32,char> mName;
};

SKYSCRAPER_END