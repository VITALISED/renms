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
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/graphics/TkColour.h>

SKYSCRAPER_BEGIN

class cTk2dObject
{
    cTkColour mColour;
    cTkVector2 mPosition;
    cTkVector2 mSize;
    cTkVector2 mAlignment;
    cTk2dObject *mpNextSibling;

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

SKYSCRAPER_END