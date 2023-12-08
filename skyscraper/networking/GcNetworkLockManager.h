/**
 * @file GcNetworkLockManager.h
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

#include <toolkit/core/types/TkID.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

class cGcNetworkLockManager
{
  public:
    struct sLock
    {
        TkID<128> mId;
        uint64_t mUA;
        cTkVector4 mSphere;
    };

    struct sNetworkLock
    {
        cGcNetworkLockManager::sLock mLock;
        float mfTimeout;
        float mfAge;
        uint16_t muRespondents;
        uint16_t muResponses;
    };

    struct sRemoteLock
    {
        cGcNetworkLockManager::sLock mLock;
        cTkUserIdBase<cTkFixedString<64, char>> mOwner;
        float mfTimeout;
        float mfAge;
    };

    cTkStackVector<cGcNetworkLockManager::sNetworkLock, 32> mLocks;
    cTkStackVector<cGcNetworkLockManager::sRemoteLock, 64> mRemoteLocks;
};

SKYSCRAPER_END