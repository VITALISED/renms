#pragma once

#include <skyscraper.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

class cGcPresetTerrainTexture
{
    cTkSmartResHandle mTerrainMaterial;
    cTkSmartResHandle mTextureDiffuseRes;
    cTkSmartResHandle mTextureNormalRes;
    std::array<cTkColour,20> maAverageColour;
    cTkFixedString<32,char> mName;
    cTkFixedString<128,char> mFilename;
};

SKYSCRAPER_END