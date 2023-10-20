#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcSpaceshipComponentData
{
    static unsigned long long muNameHash = 0x1C94F7F917E32E73;
    static unsigned long long muTemplateHash = 0x7F973269DD118BFC;

    cGcSpaceshipClasses Class;
    cTkFixedString<128,char> macCockpit;
    float mfMaxHeadTurn;
    float mfMaxHeadPitchUp;
    float mfMaxHeadPitchDown;
    int miDefaultHealth;
    float mfFoVFixedDistance;
    cTkModelRendererData Renderer;
}
