/**
 * @file GcPlayerCommunicator.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <toolkit/attachments/TkAttachment.h>

#include <simulation/player/gcplayercommunicatormessage.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerCommunicator
{
  public:
    enum eState
    {
        EState_Inactive,
        EState_SignalReceived,
        EState_RequestActive_Delay,
        EState_RequestActive,
        EState_Activating,
        EState_Active,
        EState_Deactivating,
    };

    class cGcPlayerCommunicatorSignal
    {
        cGcPlayerCommunicatorMessage mMessage;
        std::pair<TkID<128>, cTkSeed> mIDSeed;
        cTkAttachment *mpAttachment;
    };

    cGcPlayerCommunicator::cGcPlayerCommunicatorSignal mSignal;
    TkHandle mActiveNode;
    /*cGcInteractionComponent*/ uintptr_t *mpActiveInteraction;
    /*cGcNPCComponent*/ uintptr_t *mpActiveNPC;
    cGcPlayerCommunicator::eState meState;
    float mfActiveTime;
    bool mbAutoOpen;
    cGcPlayerCommunicatorMessage mDebugMessage;
    cGcPlayerCommunicator::cGcPlayerCommunicatorSignal mTakeOffCommunicatorSignal;
};

SKYSCRAPER_END