#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/gcasteroidgeneratorassignment.meta.h>

class cGcAsteroidGeneratorSurround
{
    static unsigned long long muNameHash = 0xCBF9C66D539633AF;
    static unsigned long long muTemplateHash = 0xA0845A22A01C777A;

    cGcAsteroidGeneratorAssignment Assignment;
    float mfLowerRadius;
    float mfUpperRadius;
    float mfNoiseOffset;
    float mfNoiseScale;
    float mfNoiseApply;
}
