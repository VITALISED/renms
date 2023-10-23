#pragma once

#include <skyscraper.h>
#include <toolkit/resources/TkSmartResHandle.h>

SKYSCRAPER_BEGIN

class cTkDynamicTexture
{
    cTkSmartResHandle mRenderTarget;
    int miWidth;
    int miHeight;
};

SKYSCRAPER_END