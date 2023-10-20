#pragma once
#include <metadata/metadata_common.h>
#include <metadata/user/gctriggerfeedbackstate.meta.h>

class cGcTriggerFeedbackStateTable
{
    static unsigned long long muNameHash = 0x6E458F753254E426;
    static unsigned long long muTemplateHash = 0x2B1F1319BDFB52DE;

    cTkDynamicArray<cGcTriggerFeedbackState> maEvents;
}
