/**
 * @file warning.cpp
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

#include <core/warning.h>

RENMS_HOOK(
    cTkFileSystem__IsModded, renms::RelToAbsolute(0x256EC60), bool, (uint64_t thiscall) { return true; });

RENMS_HOOK(
    cGcApplicationGameModeSelectorState__RenderWarning, renms::RelToAbsolute(0x1BF7E0), void,
    (uint64_t thiscall, const char *lpacWarningTitle, const char *lpacWarningPress, const char *lStatus1,
     char *lStatus2, float lfTimeout) {
        return RENMS_CAST(
            cGcApplicationGameModeSelectorState__RenderWarning, thiscall, "You're running ReNMS",
            "PRESS ANYTHING TO ACKNOWLEDGE",
            "ReNMS is extremely unstable. If you encounter issues check the repository for tips or to open an "
            "issue. "
            "(https://github.com/VITALISED/renms)",
            const_cast<char *>("We're not endorsed by Hello Games. Please don't send them any Zendesk Tickets."),
            lfTimeout);
    });

RENMS_BEGIN

void CreateWarningHooks()
{
    if (renms::config::gShouldShowWarning)
    {
        RENMS_DISPATCH_HOOK(cGcApplicationGameModeSelectorState__RenderWarning);
        RENMS_DISPATCH_HOOK(cTkFileSystem__IsModded);
    }
}

RENMS_END