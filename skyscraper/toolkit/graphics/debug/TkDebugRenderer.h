/**
 * @file TkDebugRenderer.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <toolkit/graphics/2d/ui/objects/text/Tk2dTextPreset.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

enum eDebugRenderMode
{
    EDebugRenderMode_Off,
    EDebugRenderMode_All,
    ENumDebugRenderModes,
};

class cTkDebugRenderer
{
  public:
    struct VertBuf
    {
        cTkVector3 *mpaVerts;
        cTkColour *mpaVertColours;
        int miNumVerts;
        bool mbDepthTest;
        cTkDebugRenderer::VertBuf *mpNext;
        float mfTime;
        cTkVector3 mvOffset;
    };

    class cTkDebugManagerText
    {
      public:
        cTkFixedString<256, char> macText;
        cTkVector3 mPosition;
        cTk2dTextPreset mPreset;
        cTkColour mColour;
        cTkVector2 mTextHeightRange;
        bool mbLog;
    };

    struct MsgBuf
    {
        cTkVector3 mvOffset;
        cTkDebugRenderer::cTkDebugManagerText maMessages[32];
        int miNumMessages;
        cTkDebugRenderer::MsgBuf *mpNext;
        float mfTime;
    };

    eDebugRenderMode meMode;
    cTkDebugRenderer::VertBuf *mpLineBuf;
    cTkDebugRenderer::VertBuf *mpLineBufAlt;
    const cTkDebugRenderer::VertBuf *mpPrevLineBuf;
    const cTkDebugRenderer::VertBuf *mpPrevLineBufAlt;
    cTkDebugRenderer::VertBuf *mpQuadBuf;
    cTkDebugRenderer::VertBuf *mpQuadBufAlt;
    const cTkDebugRenderer::VertBuf *mpPrevQuadBuf;
    const cTkDebugRenderer::VertBuf *mpPrevQuadBufAlt;
    cTkDebugRenderer::VertBuf *mpTriBuf;
    cTkDebugRenderer::VertBuf *mpTriBufAlt;
    const cTkDebugRenderer::VertBuf *mpPrevTriBuf;
    const cTkDebugRenderer::VertBuf *mpPrevTriBufAlt;
    cTkDebugRenderer::MsgBuf *mpMsgBuf;
    cTkDebugRenderer::MsgBuf *mpMsgBufAlt;
    const cTkDebugRenderer::MsgBuf *mpPrevMsgBuf;
    const cTkDebugRenderer::MsgBuf *mpPrevMsgBufAlt;
    float *mpf3dReferenceDistance;
    float *mpf3dMinScale;
    unsigned int mPrimaryThread;
    cTkVector<cTkFixedString<1024, wchar_t>> maPrevLog;
    cTkVector<cTkFixedString<1024, wchar_t>> maPrevLogAlt;
    cTkVector<cTkFixedString<1024, wchar_t>> maLog;
    cTkVector<cTkFixedString<1024, wchar_t>> maLogAlt;

    virtual void RenderText(float, float, const char *, ...);
    virtual void RenderText(float, float, const cTkColour *, const char *, ...);
    virtual void RenderText(const cTkVector2 *, const char *, float, const cTkColour *, const cTkVector2 *);
    virtual void RegisterText3D(
        const cTkVector3 *, const char *, const cTkColour *, const cTkColour *, float, const cTkVector2 *, float);
    virtual void RegisterText3D(
        const cTkPhysRelVec3 *, const char *, const cTkColour *, const cTkColour *, float, const cTkVector2 *, float);
    virtual void RenderSafeArea(const cTkColour *);
};

SKYSCRAPER_END