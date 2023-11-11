#pragma once

#include <skyscraper.h>

#include <toolkit/simulation/components/TkComponent.h>

#include <gameplay/gcgrabbablecomponentdata.meta.h>

SKYSCRAPER_BEGIN

struct sGrabbedObjectInfo
{
    cTkPhysRelMat34 mGrabMatrix;
    const cGcGrabbableComponent *mpGrabbedComponent;
    float mfMovementCompletion;
    int miDataIndex;
    bool mbIsAttached;
    bool mbGrabToggleActive;
    float mfGrabTime;
};

class cGcGrabbableComponent : public cTkComponent
{
    cGcGrabbableComponentData *mpData;
    cTkVector<TkHandle> maGrabbableNodes;
    cTkVector<TkHandle> maGrabbableNodesMoveStart;
    cTkVector<TkHandle> maGrabbableNodesMoveEnd;
    cTkVector<TkHandle> maGrabbableNodeJoints;
    cTkVector<cTkMatrix34> maGrabbableRestMatrices;
    cTkVector<cTkMatrix34> maGrabbableDesiredMatrices;
};

SKYSCRAPER_END