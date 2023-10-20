#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/projectiles/gcprojectileimpacttype.meta.h>
enum eImpactAlignment
{
    EImpactAlignment_ImpactNormal = 0,
    EImpactAlignment_GravityUp = 1,
}
enum eImpactAttachment
{
    EImpactAttachment_World = 0,
    EImpactAttachment_HitBody = 1,
}

class cGcProjectileImpactData
{
    static unsigned long long muNameHash = 0x2F2FAFA4A7023B71;
    static unsigned long long muTemplateHash = 0xA4AFE56500C79074;

    TkID<128> mEffect;
    cGcProjectileImpactType Impact;
    eImpactAlignment ImpactAlignment;
    eImpactAttachment ImpactAttachment;
}
