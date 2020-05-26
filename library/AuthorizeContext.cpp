#include "AuthorizeContext.h"

AuthorizeContext::AuthorizeContext() :
    activeUser(nullptr)
{
}

const User* AuthorizeContext::getActiveUser() const
{
    return activeUser;
}

void AuthorizeContext::setActiveUser(User* user)
{
    activeUser = user;
}
