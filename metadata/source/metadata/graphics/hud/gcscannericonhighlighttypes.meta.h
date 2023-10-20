#pragma once
#include <metadata/metadata_common.h>
enum eScannerIconHighlightType
{
    EScannerIconHighlightType_Diamond = 0,
    EScannerIconHighlightType_Hexagon = 1,
    EScannerIconHighlightType_Tag = 2,
    EScannerIconHighlightType_Octagon = 3,
    EScannerIconHighlightType_Circle = 4,
}

class cGcScannerIconHighlightTypes
{
    static unsigned long long muNameHash = 0x1E73CF8A2A7FA65D;
    static unsigned long long muTemplateHash = 0x34F3912D22FD83AB;

    eScannerIconHighlightType ScannerIconHighlightType;
}
