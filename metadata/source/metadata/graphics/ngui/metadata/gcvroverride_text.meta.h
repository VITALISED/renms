#pragma once
#include <metadata/metadata_common.h>
enum eVROverride_Text
{
    EVROverride_Text_FontHeight = 0,
    EVROverride_Text_FontIndex = 1,
}

class cGcVROverride_Text
{
    static unsigned long long muNameHash = 0x140DDCF57268A02D;
    static unsigned long long muTemplateHash = 0x96C21BF25C430F0A;

    eVROverride_Text VROverride_Text;
    int miIntValue;
    float mfFloatValue;
}
