#pragma once
#include <metadata/metadata_common.h>
enum eBlackboardType
{
    EBlackboardType_Invalid = 0,
    EBlackboardType_Float = 1,
    EBlackboardType_Integer = 2,
    EBlackboardType_Bool = 3,
    EBlackboardType_Id = 4,
    EBlackboardType_Vector = 5,
    EBlackboardType_Attachment = 6,
}

class cTkBlackboardType
{
    static unsigned long long muNameHash = 0x490DAD35C9B137EF;
    static unsigned long long muTemplateHash = 0x82614740EF36942A;

    eBlackboardType BlackboardType;
}
