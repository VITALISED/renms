#pragma once
#include <metadata/metadata_common.h>
enum eScanEventGPSHint
{
    EScanEventGPSHint_None = 0,
    EScanEventGPSHint_Accurate = 1,
    EScanEventGPSHint_OffsetNarrow = 2,
    EScanEventGPSHint_OffsetMid = 3,
    EScanEventGPSHint_OffsetWide = 4,
    EScanEventGPSHint_Obfuscated = 5,
    EScanEventGPSHint_PartObfuscated = 6,
}

class cGcScanEventGPSHint
{
    static unsigned long long muNameHash = 0x5582642D1376644E;
    static unsigned long long muTemplateHash = 0x82D9D45B58591222;

    eScanEventGPSHint ScanEventGPSHint;
}
