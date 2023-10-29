/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <simulation/environment/scanning/GcScanner.h>
#include <simulation/environment/scanning/GcScanEventManager.h>

SKYSCRAPER_BEGIN

class cGcScanManager
{
  cGcScanner mScanner;
  cGcMarkerList mMarkerList;
  cGcScanEventManager *mpScanEventManager;
  std::vector<cGcMarkerPoint,TkSTLAllocatorShim<cGcMarkerPoint,16,-1> > maFilteredMarkers;
  std::vector<enum cGcMarkerPoint::eType,TkSTLAllocatorShim<enum cGcMarkerPoint::eType,4,-1> > maMarkedPrimaryMarkerTypes;
  cGcCameraAerialViewData *mpRequestArielCamData;
  bool mbRequestArielHasPosition;
  cTkVector3 mRequestArielPosition;
  bool mbSuppressMarkers;
};

SKYSCRAPER_END