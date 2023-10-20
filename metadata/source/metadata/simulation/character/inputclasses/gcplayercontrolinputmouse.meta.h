#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eInputMouseMode
{
    EInputMouseMode_ScreenCentrePos = 0,
}
#include <?>

class cGcPlayerControlInputMouse
{
    static unsigned long long muNameHash = 0x8CC79014E9CB899E;
    static unsigned long long muTemplateHash = 0x680E1192FFA80143;

    cGcCharacterControlInputValidity Validity;
    eInputMouseMode InputMouseMode;
    cGcCharacterControlOutputSpace OutputSpace;
    TkID<128> mOutput;
    TkID<128> mOutputLength;
}
