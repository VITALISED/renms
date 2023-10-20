#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/graphics/hud/gcscannericonhighlighttypes.meta.h>

class cGcScannerIcon
{
    static unsigned long long muNameHash = 0x85905E340468CC13;
    static unsigned long long muTemplateHash = 0xBFF25FB08364A24A;

    cTkTextureResource Main;
    cTkTextureResource Small;
    cGcScannerIconHighlightTypes Highlight;
}
