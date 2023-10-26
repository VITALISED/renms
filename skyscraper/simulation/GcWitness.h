#pragma once

#include <skyscraper.h>
#include <simulation/GcTrackArrowTypes.h>
#include <toolkit/attachments/TkAttachment.h>
#include <metadata/source/simulation/ecosystem/creatures/behaviours/data/gcprimaryaxis.meta.h>

SKYSCRAPER_BEGIN

class cGcWitness
{
    cTkAttachmentPtr mpWitness;
    float mfHearingRange;
    float mfSightRange;
    float mfSightAngle;
    bool mbCanSee;
    bool mbInvestigating;
    float mfLastSightTime;
    ePrimaryAxis meAxis;
    eGcTrackArrowTypes meArrowType;
    float mfArrowTypeChangeTime;
    bool mbPermenant;
    bool (*mPerceptionCallback)(cTkAttachment *, const cTkVector3 *, bool *);
};

SKYSCRAPER_END