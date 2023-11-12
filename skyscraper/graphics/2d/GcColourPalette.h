#pragma once

#include <skyscraper.h>

#include <toolkit/utilities/containers/TkVector.h>

#include <graphics/2d/gcpalettelist.meta.h>

SKYSCRAPER_BEGIN

class cGcLegacyColourPalette
{
    std::array<cTkVector<cGcPaletteList *>, 16> maPalettes;
};

class cGcColourPalette
{
    std::array<cTkVector<cGcPaletteList *>, 16> maPalettes;
    float mfSaturationMultiplier[58];
    float mfValueMultiplier[58];
    float mfHueMultiplier[58];
    float mfRGBMultiplier[58];
};

SKYSCRAPER_END