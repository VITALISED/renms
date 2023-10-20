#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcPlayerControlInputAxis
{
    static unsigned long long muNameHash = 0x52A4BE1415A68ECA;
    static unsigned long long muTemplateHash = 0x2AAD780E27891B90;

    cGcCharacterControlInputValidity Validity;
    cGcInputActions InputX;
    cGcInputActions InputY;
    cGcCharacterControlOutputSpace OutputSpace;
    TkID<128> mOutput;
    TkID<128> mOutputLength;
}