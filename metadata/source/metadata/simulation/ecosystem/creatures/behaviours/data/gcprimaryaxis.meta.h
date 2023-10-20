#pragma once
#include <metadata/metadata_common.h>
enum ePrimaryAxis
{
    EPrimaryAxis_Z = 0,
    EPrimaryAxis_ZNeg = 1,
    EPrimaryAxis_X = 2,
    EPrimaryAxis_XNeg = 3,
    EPrimaryAxis_Y = 4,
    EPrimaryAxis_YNeg = 5,
}

class cGcPrimaryAxis
{
    static unsigned long long muNameHash = 0x839577D6883299CA;
    static unsigned long long muTemplateHash = 0x73409D6BF75AFA73;

    ePrimaryAxis PrimaryAxis;
}
