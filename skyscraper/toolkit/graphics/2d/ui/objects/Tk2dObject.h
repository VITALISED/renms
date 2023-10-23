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