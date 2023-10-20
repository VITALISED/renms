#pragma once
#include <metadata/metadata_common.h>
enum eWindowState
{
    EWindowState_Open = 0,
    EWindowState_Minimised = 1,
    EWindowState_Closed = 2,
}

class cTkNGuiWindowLayoutData
{
    static unsigned long long muNameHash = 0x9650958F04D49C46;
    static unsigned long long muTemplateHash = 0x80CA7ECB56702722;

    cTkFixedString<128,char> macName;
    cTkFixedArray<cTkFixedString<128,char>> maTabs;
    float mfPositionX;
    float mfPositionY;
    float mfSizeX;
    float mfSizeY;
    float mfSeparator;
    int miActiveTabIdx;
    float mfScrollX;
    float mfScrollY;
    eWindowState WindowState;
}
