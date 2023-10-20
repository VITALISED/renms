#pragma once
#include <metadata/metadata_common.h>
enum eActionUseType
{
    EActionUseType_Active = 0,
    EActionUseType_ActiveVR = 1,
    EActionUseType_ActiveXbox = 2,
    EActionUseType_ActivePS4 = 3,
    EActionUseType_Hidden = 4,
    EActionUseType_Debug = 5,
    EActionUseType_Obsolete = 6,
}

class cGcActionUseType
{
    static unsigned long long muNameHash = 0x498BFDCD029948EF;
    static unsigned long long muTemplateHash = 0x52A5A4E9BF42BBF;

    eActionUseType ActionUseType;
}
