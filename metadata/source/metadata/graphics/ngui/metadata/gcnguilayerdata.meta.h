#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/ngui/metadata/gcnguielementdata.meta.h>
#include <metadata/ngui/tknguigraphicstyle.meta.h>
enum eAltMode
{
    EAltMode_None = 0,
    EAltMode_Normal = 1,
    EAltMode_Alt = 2,
}

class cGcNGuiLayerData
{
    static unsigned long long muNameHash = 0x585832A31F4C2EA1;
    static unsigned long long muTemplateHash = 0x73FAEAF445FBDC01;

    cGcNGuiElementData ElementData;
    cTkNGuiGraphicStyle Style;
    cTkFixedString<128,char> macImage;
    cTkDynamicArray<cTkClassPointer> maChildren;
    cTkFixedString<128,char> macDataFilename;
    eAltMode AltMode;
}
