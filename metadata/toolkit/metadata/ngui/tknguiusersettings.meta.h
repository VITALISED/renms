#pragma once
#include <metadata/metadata_common.h>

class cTkNGuiUserSettings
{
    static unsigned long long muNameHash = 0x40643395614391FA;
    static unsigned long long muTemplateHash = 0xEEB4228A1493C3FB;

    cTkFixedString<256,char> macLastLoadedModel;
    cTkFixedString<256,char> macLastActiveLayout;
    cTkFixedArray<cTkFixedString<256,char>> maFileBrowserRecents;
}
