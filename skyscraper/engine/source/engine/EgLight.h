/**
 * @file EgLight.h
 * @author VITALISED & Contributors
 * @since 2024-01-22
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

#include <engine/source/engine/EgMaterial.h>
#include <engine/source/engine/EgRenderQueue.h>
#include <engine/source/engine/EgScene.h>

SKYSCRAPER_BEGIN

class cEgLightNodeTemplate : public cEgSceneNodeTemplate
{
  public:
    enum FalloffType
    {
        Constant,
        Linear,
        LinearSqrt,
        Quadratic,
        Cubic,
        Custom,
        NumTypes,
    };

    cTkTypedSmartResHandle<cEgMaterialResource> mpMaterialResource;
    TkID<128> msLightingContext;
    TkID<128> msShadowContext;
    float mfIntensity;
    float mfFov;
    float mfRed;
    float mfGreen;
    float mfBlue;
    unsigned int muShadowMapCount;
    float mfShadowSplitLambda;
    float mfShadowMapBias;
    float mfVolumetric;
    bool mbIsDirectional;
    cEgLightNodeTemplate::FalloffType meFalloffType;
    float mfFalloffRate;
    int miCookieIndex;
};

class cEgLightNode : public cEgRenderableSceneNode
{
  public:
    virtual ~cEgLightNode();
    virtual int GetParameterInt(int);
    virtual void SetParameterInt(int, int);
    virtual float GetParameterFloat(int, int);
    virtual void SetParameterFloat(int, int, float);
    virtual const char *GetParameterStr(int);
    virtual void SetParameterStr(int, const char *);

    cTkMatrix34 &CalculateViewMatrix();
    float GetFalloff();
    void UpdatePositionAndDirection(const cTkMatrix34 &lTransform);

    static void EnqueueFunc(
        cEgRenderQueueInfo *queueInfo, cEgRenderQueueEntry *queueEntries, cEgRenderableSceneNode **queueNodes,
        const cEgFrustum &frustum, int shadowSplitIndex, int liNumNodes, cTkDependencyCounter *);
    static void FactoryFunc(const cEgLightNodeTemplate &lNodeTemplate, cTkSlotAlloc *lpSlotAlloc);
    static cEgLightNodeTemplate *ParsingFunc(
        const cTkDynamicArray<cTkSceneNodeAttributeData> &lAttributes, cTkResourceDescriptor *lpResourceDescriptor,
        int lxResourceFlags);

    cTkVector3 mSpotDirection;
    cTkVector3 mSpotUp;
    cTkVector3 mAbsolutePosition;
    cTkColour mColour;
    TkID<128> msLightingContext;
    TkID<128> msShadowContext;
    float mfRadius;
    float mfIntensity;
    float mfFov;
    float mfVolumetric;
    int miCookieIndex;
    bool mbIsDirectional;
    bool mbDirty;
    cEgLightNodeTemplate::FalloffType meFalloffType;
    float mfFalloffRate;
};

SKYSCRAPER_END