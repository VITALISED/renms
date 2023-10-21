#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

class cTkNGuiUndoable
{
    virtual ~cTkNGuiUndoable();
    virtual void Undo();
    virtual void Do();
    virtual bool End();
    virtual void GetData();
    virtual const char ToString();
    virtual unsigned int Icon();
    cTkFixedString<64,char> mDescription;
};

SKYSCRAPER_END