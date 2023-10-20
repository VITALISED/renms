#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/hud/gcgenericicontypes.meta.h>
enum eDisplayMode
{
    EDisplayMode_Always = 0,
    EDisplayMode_SpaceOnly = 1,
    EDisplayMode_PlanetOnly = 2,
}
#include <metadata/reality/gcrealitygameicons.meta.h>

class cGcMarkerComponentData
{
    static unsigned long long muNameHash = 0x499B7E363F46B54F;
    static unsigned long long muTemplateHash = 0x9EE88E874E595E65;

    cGcGenericIconTypes Icon;
    float mfRadius;
    eDisplayMode DisplayMode;
    bool mbShipScannable;
    TkID<256> mCustomName;
    bool mbUseCustomIcon;
    cGcRealityGameIcons CustomIcon;
}
