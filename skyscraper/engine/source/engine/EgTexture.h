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
#include <engine/source/engine/EgResource.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/graphics/2d/texture/TkTextureBase.h>
#include <toolkit/graphics/2d/texture/vulkan/TkTextureVulkan.h>

SKYSCRAPER_BEGIN

class cEgTextureResource : public cEgResource
{
  cTkColour *mpaAverageColours;
  cTkColour mAverageColour;
  int miNumColours;
  eTkTextureType meTextureType;
  cTkTextureBase::eTexFormat meTextureFormat;
  unsigned int muRenderBufferObject;
  int miStreamListIndex;
  bool mbEvictionForced;
  unsigned __int8 muiHighPriorityRequested;
  int miVirtualTextureIndex;
  bool mbIsSRGB;
  bool mbHasMipMaps;
  bool mbCacheUsed;
  cTkTexture mTexture;
};

SKYSCRAPER_END