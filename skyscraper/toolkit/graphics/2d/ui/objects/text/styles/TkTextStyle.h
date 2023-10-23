#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTk2dText;

class cTkTextStyle
{
    virtual ~cTkTextStyle();
    virtual void Construct();
    virtual void Prepare();
    virtual void Update();
    virtual void Render(cTk2dText *);
    virtual void Release();
    virtual void Destruct();
};

SKYSCRAPER_END