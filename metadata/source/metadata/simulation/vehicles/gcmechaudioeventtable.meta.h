#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/vehicles/gcmechaudioevent.meta.h>

class cGcMechAudioEventTable
{
    static unsigned long long muNameHash = 0xEAC7A07BBA50D64B;
    static unsigned long long muTemplateHash = 0xDB4DCA895EB479AC;

    cGcMechAudioEvent MechEnter;
    cGcMechAudioEvent MechExit;
    cGcMechAudioEvent StepWalk;
    cGcMechAudioEvent StepRun;
    cGcMechAudioEvent TitanFallLanding;
    cGcMechAudioEvent JumpLanding;
    cGcMechAudioEvent JumpLandingSkid;
    cGcMechAudioEvent TitanFallPoseIntro;
    cGcMechAudioEvent JetpackTrigger;
    cGcMechAudioEvent JetpackRetrigger;
    cGcMechAudioEvent JetpackLP;
    cGcMechAudioEvent JetpackLPEnd;
}
