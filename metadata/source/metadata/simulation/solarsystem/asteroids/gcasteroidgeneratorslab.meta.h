#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcAsteroidGeneratorSlab
{
    static unsigned long long muNameHash = 0xA7877CF3CA740744;
    static unsigned long long muTemplateHash = 0x973E87BA87F7C61A;

    cGcAsteroidGeneratorAssignment Assignment;
    cTkVector3 mRotation;
    cTkVector3 mScale;
    float mfNoiseOffset;
    float mfNoiseScale;
    float mfNoiseApply;
}
