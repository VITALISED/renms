#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcExpeditionEventTable
{
    static unsigned long long muNameHash = 0xD5BCFB328D8A80A8;
    static unsigned long long muTemplateHash = 0xD6EA01BF44C4D0EA;

    cTkDynamicArray<cGcExpeditionEventData> maEvents;
    cTkDynamicArray<cGcExpeditionInterventionEventData> maInterventionEvents;
}
