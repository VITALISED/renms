#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcWikiPage
{
    static unsigned long long muNameHash = 0x8762991A70BCCE8C;
    static unsigned long long muTemplateHash = 0xCA108AAA63D6579B;

    TkID<256> mPageID;
    cTkTextureResource Icon;
    cTkFixedString<64,char> macContent;
    cTkFixedString<64,char> macVRContent;
    cTkTextureResource ContentImage;
}
