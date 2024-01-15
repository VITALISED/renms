/**
 * @file GcAtlasSendReport.h
 * @author VITALISED & Contributors
 * @since 2024-01-15
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <atlas/broker/GcAtlasShared.h>
#include <toolkit/data/TkMetaDataClasses.h>

#include <gamestate/gcuniverseaddressdata.meta.h>

SKYSCRAPER_BEGIN

enum ePackageType
{
    EPackageType_Unknown,
    EPackageType_Discovery,
    EPackageType_Message,
    EPackageType_NumTypes,
};

class cGcAtlasSendReport : public cGcAtlasShared
{
  public:
    virtual ~cGcAtlasSendReport() final;

    ePackageType mePackageType;
    cTkFixedString<64, char> macRID;
    cGcUniverseAddressData mUniverseAddress;
    cTkFixedString<32, char> macRL;
    cTkFixedString<32, char> macRC;
};

SKYSCRAPER_END