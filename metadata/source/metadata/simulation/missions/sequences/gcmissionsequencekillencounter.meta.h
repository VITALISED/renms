#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceKillEncounter
{
    static unsigned long long muNameHash = 0x7E1936B219E215F;
    static unsigned long long muTemplateHash = 0xDFFCBF31D181A7F9;

    cTkFixedString<128,char> macMessage;
    TkID<256> mEncounterComponentScanEvent;
    bool mbAllowedToEscape;
    cTkFixedString<128,char> macDebugText;
}
