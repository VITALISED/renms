#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcbytebeattoken.meta.h>
#include <metadata/audio/gcbytebeattemplate.meta.h>

class cGcByteBeatTemplate
{
    static unsigned long long muNameHash = 0xB764F802BDE36ADF;
    static unsigned long long muTemplateHash = 0x972ED2E5C097966E;

    float mfWeight;
    cGcByteBeatToken TokenType;
    int miMinValue;
    int miMaxValue;
    cTkDynamicArray<cGcByteBeatTemplate> maChildren;
}
