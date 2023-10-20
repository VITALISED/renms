#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkmodelresource.meta.h>
#include <metadata/simulation/gcfreighterdungeonchoice.meta.h>
#include <metadata/tktextureresource.meta.h>

class cGcAbandonedFreighterComponentData
{
    static unsigned long long muNameHash = 0x95028D8CB7957BEF;
    static unsigned long long muTemplateHash = 0xDFC505E8066AB0E7;

    cTkModelResource DungeonRootScene;
    cTkDynamicArray<cGcFreighterDungeonChoice> maDungeonOptions;
    TkID<256> mMarkerLabel;
    cTkTextureResource MarkerIcon;
}
