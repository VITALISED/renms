#pragma once
#include <metadata/metadata_common.h>
enum eGraphicDetail
{
    EGraphicDetail_Low = 0,
    EGraphicDetail_Medium = 1,
    EGraphicDetail_High = 2,
    EGraphicDetail_Ultra = 3,
}

class cTkGraphicsDetailTypes
{
    static unsigned long long muNameHash = 0xAACA1A6A0194D948;
    static unsigned long long muTemplateHash = 0x4EF1F56CF5CA5B73;

    eGraphicDetail GraphicDetail;
}
