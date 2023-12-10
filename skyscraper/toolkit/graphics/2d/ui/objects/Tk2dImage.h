/**
 * @file Tk2dImage.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <toolkit/graphics/2d/texture/TkDynamicTexture.h>
#include <toolkit/graphics/2d/texture/vulkan/TkTextureVulkan.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dObject.h>

SKYSCRAPER_BEGIN

class cTk2dImage : public cTk2dObject
{
  public:
    cTkVector2 maUVs[4];
    cTkTexture *mpTexture;
    cTkDynamicTexture *mpDynamicTexture;
    float mfTextureMipLevel;
    bool mbVisible;
    bool mbTiledUV;
    bool mbIsRenderTarget;

    virtual void Construct(const cTkVector2 *, const cTkVector2 *, const cTkVector2 *, const cTkColour *);
    virtual void Prepare();
    virtual void Update(float);
    virtual void Render();
    virtual void Release();
    virtual void Destruct();
    virtual void SetPosition(const cTkVector2 *);
    virtual cTkVector2 *GetPosition(cTkVector2 *result, const cTkVector2 *);
    virtual cTkVector2 *GetPosition(cTkVector2 *result);
    virtual cTkVector2 *GetWorldTopLeft(cTkVector2 *result);
    virtual void SetSize(const cTkVector2 *);
    virtual cTkVector2 *GetSize(cTkVector2 *result);
    virtual void SetColour(const cTkColour *);
    virtual cTkColour *GetColour(cTkColour *result);
    virtual void SetAlignment(const cTkVector2 *);
    virtual cTkVector2 *GetAlignment(cTkVector2 *result);
    virtual bool RemoveAllObjects();
};

class cTk2dImageEx : public cTk2dImage
{
  public:
    cTkSmartResHandle mResource;
};

SKYSCRAPER_END