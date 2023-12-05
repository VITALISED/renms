/**
 * @file TkHttp.h
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

#pragma once

#include <skyscraper.h>

#include <toolkit/data/TkMetaDataClasses.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/network/TkURL.h>

SKYSCRAPER_BEGIN

namespace Http
{

typedef int Verb;

enum StatusCode
{
    HTTP_ERROR                  = 0xFFFFFFFF,
    HTTP_CONTINUE               = 0x64,
    HTTP_SWITCHING_PROTOCOLS    = 0x65,
    HTTP_OK                     = 0xC8,
    HTTP_CREATED                = 0xC9,
    HTTP_ACCEPTED               = 0xCA,
    HTTP_NOT_AUTHORITATIVE      = 0xCB,
    HTTP_NO_CONTENT             = 0xCC,
    HTTP_RESET_CONTENT          = 0xCD,
    HTTP_PARTIAL_CONTENT        = 0xCE,
    HTTP_MULTIPLE_CHOICES       = 0x12C,
    HTTP_MOVED_PERMANENTLY      = 0x12D,
    HTTP_MOVED_TEMPORARILY      = 0x12E,
    HTTP_SEE_OTHER              = 0x12F,
    HTTP_NOT_MODIFIED           = 0x130,
    HTTP_USE_PROXY              = 0x131,
    HTTP_BAD_REQUEST            = 0x190,
    HTTP_UNAUTHORIZED           = 0x191,
    HTTP_PAYMENT_REQUIRED       = 0x192,
    HTTP_FORBIDDEN              = 0x193,
    HTTP_NOT_FOUND              = 0x194,
    HTTP_METHOD_NOT_ALLOWED     = 0x195,
    HTTP_NOT_ACCEPTABLE         = 0x196,
    HTTP_PROXY_AUTHENTICATION   = 0x197,
    HTTP_REQUEST_TIMEOUT        = 0x198,
    HTTP_CONFLICT               = 0x199,
    HTTP_GONE                   = 0x19A,
    HTTP_LENGTH_REQUIRED        = 0x19B,
    HTTP_PRECONDITION           = 0x19C,
    HTTP_REQUEST_TOO_LARGE      = 0x19D,
    HTTP_URI_TOO_LONG           = 0x19E,
    HTTP_UNSUPPORTED_MEDIATYPE  = 0x19F,
    HTTP_RANGE_NOT_SATISFIABLE  = 0x1A0,
    HTTP_EXPECTATION_FAILED     = 0x1A1,
    HTTP_IM_A_TEAPOT            = 0x1A2,
    HTTP_AUTHENTICATION_TIMEOUT = 0x1A3,
    HTTP_METHOD_FAILURE         = 0x1A4,
    HTTP_UPGRADE_REQUIRED       = 0x1AA,
    HTTP_TOO_MANY_REQUESTS      = 0x1AD,
    HTTP_APP_ASSERT             = 0x1B0,
    HTTP_SERVER_ERROR           = 0x1F4,
    HTTP_NOT_IMPLEMENTED        = 0x1F5,
    HTTP_BAD_GATEWAY            = 0x1F6,
    HTTP_SERVICE_UNAVAILABLE    = 0x1F7,
    HTTP_GATEWAY_TIMEOUT        = 0x1F8,
    HTTP_NOT_SUPPORTED          = 0x1F9,
};

struct KnownHeader
{
    typedef int Enum;
};

struct Request
{
    cGcURL mURL;
    uint64_t mu64UserData;
    cTkDynamicArray<char> mPostData;
    uint8_t mePostDataType[4];
    Http::Verb meVerb;
    cTkVector<std::pair<Http::KnownHeader::Enum, std::string>> mCustomHeaders;
};

struct RequestResult
{
    struct State
    {
        typedef int Enum;
    };

    Http::RequestResult::State::Enum meState;
    Http::StatusCode meHttpStatus;
    uint64_t mu64UserData;
    Http::Request *mpRequest;
    const char *mpacBuffer;
    uint64_t mu64BufferLength;
};

} // namespace Http

SKYSCRAPER_END