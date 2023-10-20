#pragma once
#include <metadata/metadata_common.h>
enum eByteBeatToken
{
    EByteBeatToken_T = 0,
    EByteBeatToken_AND = 1,
    EByteBeatToken_OR = 2,
    EByteBeatToken_XOR = 3,
    EByteBeatToken_Plus = 4,
    EByteBeatToken_Minus = 5,
    EByteBeatToken_Multiply = 6,
    EByteBeatToken_Divide = 7,
    EByteBeatToken_Modulo = 8,
    EByteBeatToken_ShiftLeft = 9,
    EByteBeatToken_ShiftRight = 10,
    EByteBeatToken_Greater = 11,
    EByteBeatToken_GreaterEqual = 12,
    EByteBeatToken_Less = 13,
    EByteBeatToken_LessEqual = 14,
    EByteBeatToken_Number = 15,
    EByteBeatToken_OpenParenthesis = 16,
    EByteBeatToken_CloseParenthesis = 17,
}

class cGcByteBeatToken
{
    static unsigned long long muNameHash = 0x1FC756C2E641CC49;
    static unsigned long long muTemplateHash = 0xA3F301BA6206E62D;

    eByteBeatToken ByteBeatToken;
}
