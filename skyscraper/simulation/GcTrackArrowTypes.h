#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

enum eGcTrackArrowTypes
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
    ETrackArrow_NumTypes = 24,
};

SKYSCRAPER_END