#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcplayercommunicatormessageweighted.meta.h>

class cGcShipDialogue
{
    static unsigned long long muNameHash = 0x770E3F1934F2D769;
    static unsigned long long muTemplateHash = 0x6ACF873797BDBD79;

    cTkFixedArray<cGcPlayerCommunicatorMessageWeighted> maDialogueTree;
}
