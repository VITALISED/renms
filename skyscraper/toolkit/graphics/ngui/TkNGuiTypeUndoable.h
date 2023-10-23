#pragma once

#include <toolkit/graphics/ngui/TkNGuiUndoable.h>

template <typename T>
class cTkNGuiTypeUndoable : public cTkNGuiUndoable
{
    T mFrom;
    T mTo;
    T *mpValue;
};
