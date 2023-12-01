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

#include <toolkit/utilities/TkString.h>

#include <metadata/toolkit/system/tkuserserviceauthprovider.meta.h>

SKYSCRAPER_BEGIN

class ITkUserServiceNotifications
{
  public:
    struct AuthToken
    {
        eAuthProvider meProvider;
        unsigned char meAuthEnvironment[4];
        cTkFixedString<3072, char> mTokenString;
        std::string mAuthHeader;
        std::string mOAuth;
        std::string mNonce;
    };

    virtual ~ITkUserServiceNotifications()                                                                  = 0;
    virtual void AuthenticationTokenArrived(const uint64_t, const ITkUserServiceNotifications::AuthToken *) = 0;
    virtual void AuthenticationTokenFailed(const uint64_t)                                                  = 0;
    virtual void ServiceStateChanged()                                                                      = 0;
};

SKYSCRAPER_END