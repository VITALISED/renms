#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/2d/ngui/TkNGuiAnimationData.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/graphics/TkFrameData.h>

SKYSCRAPER_BEGIN

class cTkNGuiElementData
{
    cTkNGuiAnimationData mAnimationData;
    cTkFrameData<float> mfCurrentOffset;
    cTkFrameData<float> mfScrollOffset;
    cTkFrameData<float> mfStartTime;
    cTkFrameData<eNGuiInputType> meLastInput;
    cTkFrameData<bool> mbLastDraw;
};

SKYSCRAPER_END