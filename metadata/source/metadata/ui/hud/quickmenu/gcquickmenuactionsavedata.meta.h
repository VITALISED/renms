#pragma once
#include <metadata/metadata_common.h>
#include <metadata/ui/hud/quickmenu/gcquickmenuactions.meta.h>
#include <metadata/gamestate/gcinventoryindex.meta.h>

class cGcQuickMenuActionSaveData
{
    static unsigned long long muNameHash = 0x15BEBD4BD6DD1244;
    static unsigned long long muTemplateHash = 0xA7329F7D002F1EE4;

    cGcQuickMenuActions Action;
    TkID<128> mId;
    int miNumber;
    cGcInventoryIndex InventoryIndex;
}
