#pragma once
#include <metadata/metadata_common.h>
enum eMenuToClose
{
    EMenuToClose_QuickMenu = 0,
    EMenuToClose_BuildMenu = 1,
    EMenuToClose_Inventory = 2,
    EMenuToClose_AllDetailMessages = 3,
}

class cGcMissionSequenceCloseMenu
{
    static unsigned long long muNameHash = 0xE62B86A237CB0756;
    static unsigned long long muTemplateHash = 0xC1ACA35E74A19273;

    float mfDelay;
    eMenuToClose MenuToClose;
    cTkFixedString<128,char> macDebugText;
}
