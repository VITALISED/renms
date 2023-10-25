#pragma once

#include <skyscraper.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dObject.h>
#include <toolkit/graphics/2d/texture/vulkan/TkTextureVulkan.h>
#include <toolkit/graphics/2d/texture/TkDynamicTexture.h>

SKYSCRAPER_BEGIN

class cTk2dImage : public cTk2dObject
{
	cTkVector2 maUVs[4];
	cTkTexture* mpTexture;
	cTkDynamicTexture* mpDynamicTexture;
	float mfTextureMipLevel;
	bool mbVisible;
	bool mbTiledUV;
	bool mbIsRenderTarget;
};

SKYSCRAPER_END