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

#include "../renms.h"
#include <functional>
#include <type_traits>

RENMS_BEGIN

namespace detail // EDIT: make it an implementation detail
{
template <typename T>
struct deduce_type;

template <typename RETURN_TYPE, typename CLASS_TYPE, typename... ARGS>
struct deduce_type<RETURN_TYPE (CLASS_TYPE::*)(ARGS...) const>
{
    using type = std::function<RETURN_TYPE(ARGS...)>;
};
} // namespace detail

template <typename CLOSURE>
auto wrap(const CLOSURE &fn) // EDIT: give it a better name
{
    return typename detail::deduce_type<decltype(&CLOSURE::operator())>::type(fn);
}

#define RENMS_HOOK(name, offset, detour) \
    auto F    = renms::wrap(detour);     \
    auto name = renms::HookFunction<decltype(F)>(#name, &F, offset);

template <typename Fn>
class HookFunction
{
  private:
    char *mpacID;
    Fn *mpDetour;
    MH_STATUS mLastHookRes;

  public:
    LPVOID *mppOriginal;
    LPVOID mpOffset;
    bool mbIsActive;

    HookFunction(char *lpacID, Fn *lpDetour, LPVOID lpOffset);
    ~HookFunction();

    bool Toggle();
    bool SetEnabled();
    bool SetDisabled();
};

RENMS_END

#include "hooks.tpp"
