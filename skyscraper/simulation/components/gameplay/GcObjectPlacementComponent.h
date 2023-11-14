#pragma once

#include <skyscraper.h>

#include <toolkit/attachments/TkHandle.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gameplay/gcobjectplacementcomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcObjectPlacementComponent : public cTkComponent
{
    typedef cGcNPCPlacementComponent::ePlaceObjectState ePlaceObjectState;

    cGcObjectPlacementComponent::ePlaceObjectState meObjectPlacementState;
    TkHandle mGroupNode;
    TkHandle mNode;
    int miNumObjectsAdded;
    int miNumGroupsAdded;
    cTkVector3 mPrevPosition;
    cTkVector<cTkMatrix34> maStartMatrices;
    cTkVector<float> mafOffsets;
    unsigned __int64 mSeed;
    cGcObjectPlacementComponentData *mpData;
};

SKYSCRAPER_END