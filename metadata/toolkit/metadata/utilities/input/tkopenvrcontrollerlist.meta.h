#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/input/tkopenvrcontrollerlookup.meta.h>

class cTkOpenVRControllerList
{
    static unsigned long long muNameHash = 0x9BF04097261BBFEA;
    static unsigned long long muTemplateHash = 0x37F80B4F24A556F4;

    cTkDynamicArray<cTkOpenVRControllerLookup> maDevices;
}
