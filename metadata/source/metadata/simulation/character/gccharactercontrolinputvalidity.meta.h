#pragma once
#include <metadata/metadata_common.h>
enum eCharacterControlInputValidity
{
    ECharacterControlInputValidity_Always = 0,
    ECharacterControlInputValidity_PadOnly = 1,
    ECharacterControlInputValidity_KeyboardAnMouseOnly = 2,
}

class cGcCharacterControlInputValidity
{
    static unsigned long long muNameHash = 0x1A9351C5A8C07BA4;
    static unsigned long long muTemplateHash = 0x28FD8E5FE5649E4B;

    eCharacterControlInputValidity CharacterControlInputValidity;
}
