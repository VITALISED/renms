#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/components/gameplay/gcinteractiontype.meta.h>
#include <metadata/reality/gcalienrace.meta.h>

class cGcRewardIncrementInteractionIndex
{
    static unsigned long long muNameHash = 0x317FB72CFB424340;
    static unsigned long long muTemplateHash = 0x27D37C5056DB167A;

    cGcInteractionType InteractionToIncrement;
    cGcAlienRace Race;
}
