#pragma once

#include "hkVector4f.h"
#include "hkQuaternionf.h"

struct hknpMassDistribution
{
    hkVector4f m_centerOfMassAndVolume;
    hkQuaternionf m_majorAxisSpace;
    hkVector4f m_inertiaTensor;
};