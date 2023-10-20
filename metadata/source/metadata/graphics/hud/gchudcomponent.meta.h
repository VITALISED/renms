#pragma once
#include <metadata/metadata_common.h>
enum eAlign
{
    EAlign_Center = 0,
    EAlign_TopLeft = 1,
    EAlign_TopRight = 2,
    EAlign_BottomLeft = 3,
    EAlign_BottomRight = 4,
}

class cGcHUDComponent
{
    static unsigned long long muNameHash = 0x9658E308A74D3E3C;
    static unsigned long long muTemplateHash = 0x3585F426181D439A;

    TkID<128> mID;
    int miPosX;
    int miPosY;
    int miWidth;
    int miHeight;
    eAlign Align;
}
