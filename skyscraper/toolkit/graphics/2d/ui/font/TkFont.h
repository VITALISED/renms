#pragma once

#include <skyscraper.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cTkCharDescr
{
    __int16 srcX;
    __int16 srcY;
    __int16 srcW;
    __int16 srcH;
    __int16 xOff;
    __int16 yOff;
    __int16 xAdv;
    __int16 page;
    unsigned int chnl;
    cTkVector<short> kerningPairs;
};


class cTkFont
{
    cTkTexture *mpTexture;
    cTkSmartResHandle mTextureRes;
    __int16 miFontHeight;
    __int16 miCharWidthMin;
    __int16 miCharPad;
    __int16 mu8BaseLine;
    __int16 mu8ScaleW;
    __int16 mu8ScaleH;
    std::array<cTkCharDescr,1024> maCharacters;
    std::array<short,65536> maiCharacterLookup;
    int miNumMappedChars;
    __int16 miDefaultCharacterIndex;
    float mfScale;
    bool mbLoaded;
};

SKYSCRAPER_END