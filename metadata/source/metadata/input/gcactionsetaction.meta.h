#pragma once
#include <metadata/metadata_common.h>
#include <metadata/input/gcactionusetype.meta.h>
#include <metadata/utilities/input/actions/gcinputactions.meta.h>

class cGcActionSetAction
{
    static unsigned long long muNameHash = 0xF69368BA4545C60E;
    static unsigned long long muTemplateHash = 0xDA8E64ABBB9ABBC9;

    cGcActionUseType Status;
    cGcInputActions Action;
}
