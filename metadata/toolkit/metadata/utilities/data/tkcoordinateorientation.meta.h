#pragma once
#include <metadata/metadata_common.h>
enum eCoordinateOrientation
{
    ECoordinateOrientation_None = 0,
    ECoordinateOrientation_Random = 1,
}

class cTkCoordinateOrientation
{
    static unsigned long long muNameHash = 0x5F02C151C26450C8;
    static unsigned long long muTemplateHash = 0x1AEBC22B3DE06B75;

    eCoordinateOrientation CoordinateOrientation;
}
