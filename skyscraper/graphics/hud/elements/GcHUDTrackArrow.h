/**
 * @file GcHUDTrackArrow.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

SKYSCRAPER_BEGIN

enum eGcTrackArrowTypes : __int32
{
    ETrackArrow_WantedCombat,
    ETrackArrow_WantedHunting,
    ETrackArrow_Investigate,
    ETrackArrow_Predator,
    ETrackArrow_HazardHot,
    ETrackArrow_HazardCold,
    ETrackArrow_HazardRadiation,
    ETrackArrow_HazardToxic,
    ETrackArrow_ShipsArriving,
    ETrackArrow_PiratesArriving,
    ETrackArrow_PoliceArriving,
    ETrackArrow_Ship,
    ETrackArrow_PrimaryShip,
    ETrackArrow_SecondaryShip,
    ETrackArrow_Freighter,
    ETrackArrow_Missile,
    ETrackArrow_Building,
    ETrackArrow_Friend,
    ETrackArrow_FriendScared,
    ETrackArrow_FriendSearching,
    ETrackArrow_NetworkPlayer,
    ETrackArrow_Fiend,
    ETrackArrow_Repair,
    ETrackArrow_Summoning,
    ETrackArrow_NumTypes,
};

SKYSCRAPER_END