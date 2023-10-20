#pragma once
#include <metadata/metadata_common.h>
#include <metadata/effects/tkshearwindoctavedata.meta.h>

class cTkShearWindData
{
    static unsigned long long muNameHash = 0xB9B8ADD8C9FFC2D8;
    static unsigned long long muTemplateHash = 0xC462D4F8119851CF;

    TkID<128> mName;
    float mfOverallWindStrength;
    float mfLdsWindStrength;
    float mfLdsWindSpeed;
    float mfShearWindSpeed;
    float mfWindShearVertpushStrength;
    float mfWindShearGradientStrength;
    float mfWindShearToDotLdsFactor;
    float mfWindStrengthToVertpush;
    cTkShearWindOctaveData Octave0;
    cTkShearWindOctaveData Octave1;
    cTkShearWindOctaveData Octave2;
    cTkShearWindOctaveData Octave3;
}
