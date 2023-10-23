#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkString.h>
#include <metadata/system/tkuserserviceauthprovider.meta.h>

class ITkUserServiceNotifications
{
    struct AuthToken
    {
        eAuthProvider meProvider;
        unsigned char meAuthEnvironment[4];
        cTkFixedString<3072,char> mTokenString;
        std::string mAuthHeader;
        std::string mOAuth;
        std::string mNonce;
    };

    virtual ~ITkUserServiceNotifications();
    virtual void AuthenticationTokenArrived(const unsigned __int64, const ITkUserServiceNotifications::AuthToken *);
    virtual void AuthenticationTokenFailed(const unsigned __int64);
    virtual void ServiceStateChanged();
};
