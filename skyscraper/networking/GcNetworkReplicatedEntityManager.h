/**
 * @file GcNetworkReplicatedEntityManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <networking/GcNetworkPlayerEventsHandler.h>
#include <networking/messages/GcNetworkReplicatedEntitiesReplicatedVariablesMessage.h>
#include <networking/messages/GcNetworkReplicatedEntitiesWelcomeMessage.h>
#include <simulation/environment/GcEnvironment.h>
#include <toolkit/networking/TkNetworkId.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/customisation/gccustomisationcomponentdata.meta.h>
#include <simulation/solarsystem/planet/gcplanetcolourdata.meta.h>
#include <toolkit/components/networking/tknetreplicatedentitycomponentdata.meta.h>

SKYSCRAPER_BEGIN

struct NetReplicatedCustomisationData
{
    cTkSeed mSeed;
    eCustomisationDataType meCustomisationDataType;
    cTkVector<int> maDescriptorGroupIndicies;
    cTkVector<int> maColourOptionIndicies;
    cTkVector<cTkVector<std::pair<int, int>>> maTextureOptionIndicies;
    std::map<TkID<128>, float, std::less<TkID<128>>> mBoneScales;
    bool mbEditedColours;
    bool mbUseLegacyColourPalettes;
    float mfScale;
};

struct sGcNetworkReplicatedPetEntityData
{
    cGcPlanetColourData mColourPalette;
    cTkResourceDescriptor mDescriptor;
    cTkSeed mColourBaseSeed;
    cTkSeed mBoneScaleSeed;
    eBiome meBiome;
    float mfBabify;
};

class cGcNetworkReplicatedEntityManager : public INetworkPlayerEventsHandler
{
  public:
    struct sNetworkContext
    {
        cTkUserIdBase<cTkFixedString<64, char>> mPlayerId;
        cTkNetworkId mNetworkId;
        uint64_t miInstanceID;
        eReplicationRange meReplicationRangeOverride;
        bool mbStartActivated;
    };

    struct EntityRequest
    {
        enum eRequestStates
        {
            ERequestState_RequestResource,
            ERequestState_WaitingForResource,
            ERequestState_CheckResourceLoaded,
            ERequestState_AddNode,
            ERequestState_Complete,
            ERequestState_Invalid,
        };
        std::shared_ptr<sGcNetworkReplicatedEntitiesWelcomeMessage const> mpMessage;
        cTkSmartResHandle mResHandle;
        cTkSmartResHandle mExtraResHandle;
        cTkPhysRelMat34 mLocation;
        cTkUserIdBase<cTkFixedString<64, char>> mOwnerPlayerId;
        cTkNetworkId mNetworkId;
        NetReplicatedCustomisationData mCustomisationData;
        sGcNetworkReplicatedPetEntityData mPetData;
        bool mbCustomised;
        bool mbPet;
        bool mbRemove;
        bool mbFemale;
        bool mbBaby;
        bool mbProcedural;
        bool mbSimplePhysics;
        cGcNetworkReplicatedEntityManager::EntityRequest::eRequestStates meState;
        cTkFixedString<128, char> mPath;
        cTkFixedString<128, char> mExtraPath;
        cTkSeed mSeed;
        cTkSeed mSecondarySeed;
        TkID<128> mID;
        eReplicationRange meReplicationRange;
        uint64_t miInstanceID;
        uint64_t miTimeCreated;
        cTkVector<std::shared_ptr<sGcNetworkReplicatedEntitiesReplicatedVariablesMessage>> maReplicatedVariableMessages;
    };

    cTkVector<std::unique_ptr<cGcNetworkReplicatedEntityManager::EntityRequest>> mRequests;
    cGcNetworkReplicatedEntityManager::sNetworkContext mNetworkContext;
    EnvironmentLocation::Enum meLocalEnvironmentLocation;
};

SKYSCRAPER_END