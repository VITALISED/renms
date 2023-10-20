#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cTkAnimPoseComponentData
{
    static unsigned long long muNameHash = 0x6DF806B869216436;
    static unsigned long long muTemplateHash = 0xC073B9F61779E1C7;

    cTkDynamicArray<cTkAnimPoseData> maPoseAnims;
    cTkFixedString<128,char> macFilename;
    cTkDynamicArray<cTkAnimPoseCorrelationData> maCorrelations;
    cTkDynamicArray<cTkAnimPoseExampleData> maExamples;
    cTkDynamicArray<float> maCorrelationMat;
    float mfAdultCorrelationValue;
    cTkDynamicArray<cTkAnimPoseBabyModifier> maBabyModifiers;
    bool mbShouldRandomise;
}