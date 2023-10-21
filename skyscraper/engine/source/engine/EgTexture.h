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