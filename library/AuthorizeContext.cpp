#include "AuthorizeContext.h"

const User* AuthorizeContext::getActiveUser() const
{
    return activeUser;
}

void AuthorizeContext::setActiveUser(User* user)
{
    activeUser = user;
}
