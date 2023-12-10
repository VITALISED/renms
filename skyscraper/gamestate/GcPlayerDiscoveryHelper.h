/**
 * @file GcPlayerDiscoveryHelper.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <gamestate/GcDiscoverySearch.h>

SKYSCRAPER_BEGIN

class cGcPlayerDiscoveryHelper
{
  public:
    enum eDiscoveryHelperEvent
    {
        EDiscoveryHelperEvent_None,
        EDiscoveryHelperEvent_ShowPlanetMessage,
        EDiscoveryHelperEvent_ShowSystemMessage,
        EDiscoveryHelperEvent_ShowBlackHoleMessage,
        EDiscoveryHelperEvent_ShowAtlasStationMessage,
        EDiscoveryHelperEvent_ShowPostBlackHoleWarpMessage,
        EDiscoveryHelperEvent_WaitForResultsAndShowDiscoveryMission,
        EDiscoveryHelperEvent_ShowPlayerBaseMessage,
        EDiscoveryHelperEvent_ShowPostRelicGateWarpMessage,
        EDiscoveryHelperEvent_ShowPostFreighterMegaWarpMessage,
    };

    struct DiscoveryHelperEvent
    {
        cGcPlayerDiscoveryHelper::eDiscoveryHelperEvent meEvent;
        float mfWaitTime;
        float mfDuration;
    };

    int miDiscoveredCreatures;
    int miTotalDiscoverableCreatures;
    const int kiNotifyIfDiscoveredLessThan;
    std::forward_list<cGcPlayerDiscoveryHelper::DiscoveryHelperEvent> maEvents;
    cGcDiscoverySearch *mDiscoverySearch;
    cTkSeed mCreatureSeed;
    bool mPendingDiscoveryNew;
};

SKYSCRAPER_END