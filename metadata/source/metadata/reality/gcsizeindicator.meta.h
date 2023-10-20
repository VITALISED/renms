#pragma once
#include <metadata/metadata_common.h>
enum eSizeIndicator
{
    ESizeIndicator_Small = 0,
    ESizeIndicator_Medium = 1,
    ESizeIndicator_Large = 2,
}

class cGcSizeIndicator
{
    static unsigned long long muNameHash = 0x22715A99B359A960;
    static unsigned long long muTemplateHash = 0xDADE724C336C1487;

    eSizeIndicator SizeIndicator;
}
