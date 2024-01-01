/**
 * @file TkPhysicsComponent.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/simulation/physics/havok/TkCollision.h>
#include <toolkit/simulation/physics/havok/TkPhysicsConstraint.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <toolkit/components/physics/tkdynamicchaincomponentdata.meta.h>
#include <toolkit/components/physics/tkphysicscomponentdata.meta.h>
#include <toolkit/physics/ragdoll/tkragdolldata.meta.h>

SKYSCRAPER_BEGIN

class cTkPhysicsComponent : public cTkComponent
{
  public:
    struct SubBody
    {
        cTkCollision *mpColl;
        cTkRigidBody *mpBody;
        cTkPhysicsConstraint *mpConstraint;
        TkHandle muNode;
        cTkVector3 mvScale;
        cTkDynamicChainComponentData *mpChainData;
        cTkRagdollData *mpRagdollData;
    };

    struct RagdollVelTracker
    {
        cTkVector3 mvPrevLoc;
        TkHandle muNode;
        int miParentInd;
        bool mbChainEnd;
    };

    cTkPhysicsComponentData *mpData;
    TkHandle muNode;
    cTkRigidBody mRigidBody;
    cTkCollision mCollision;
    cTkCollision mComplexCollision;
    TkHandle mNextNodeToBuildCollision;
    cTkStackVector<TkHandle, 16> maNodesToIgnoreBuildingCollision;
    cTkMatrix34 mGraphicsToPhysics;
    cTkMatrix34 mPhysicsToGraphics;
    cTkVector3 mGraphicsScale;
    float mfAirThicknessMult;
    float mfMotorStrengthMult;
    float mfWindStrengthMult;
    float mfRagdollTau;
    float mfRagdollDamping;
    float mfRagdollConeLimit;
    float mfRagdollTwistLimit;
    float mfRagdollJointFriction;
    float mfRagdollGravityFactor;
    float mfRagdollLinearDamping;
    float mfRagdollTauFadeStartTime;
    float mfRagdollTauFadeEndTime;
    float mfRagdollLifetime;
    int miRagdollFrameCountdown;
    int miRagdollImpactFrameCnt;
    uint16_t muRagdollCollisionMask;
    cTkVector3 mvRagdollInitialVelocity;
    bool mbPrepared;
    bool mbLevelGraphicsMatrix;
    bool mbForceGraphicsFollow;
    bool mbModelOwnerSearched;
    bool mbIsModelOwner;
    bool mbRagdollRequested;
    bool mbHasJointChain;
    bool mbHasRagdolled;
    bool mbUsingRagdollCollision;
    bool mbExplodeRequested;
    bool mbHasCodeDrivenSubBodies;
    bool mbHasExploded;
    bool mbIsExplosionType;
    float mfExplodeCollsionCountdown;
    bool mbPhysicsUpdateFromGraphicsEnabled;
    bool mbUsingSimpleCollision;
    bool mbUsingSimpleCharacterCollision;
    bool mbBreakOnPostPhysUpdate;
    bool mbDraw;
    bool mbDrawJointHierarchy;
    bool mbPrintSkel;
    TkHandle mHighlightedNode;
    TkHandle mSelectedNode;
    cTkVector3 mvRagdollImpactDir;
    cTkVector3 mvRagdollImpactPos;
    cTkVector<cTkPhysicsConstraint *> mapConstraints_;
    cTkVector<cTkPhysicsComponent::SubBody> maSubBodies;
    cTkVector<cTkPhysicsComponent::RagdollVelTracker> maVelTrackers;
    cTkVector<int> maJointsToUpdateTransformsForInRagdoll;
};

SKYSCRAPER_END