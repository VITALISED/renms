#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class ITkNGuiDraggable
{
    virtual void Render() = 0;
    virtual int GetType() = 0;
};

SKYSCRAPER_END