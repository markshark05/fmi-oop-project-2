#pragma once
#include "User.h"
class AuthorizeContext
{
public:
    AuthorizeContext();
    const User* getActiveUser() const;
    void setActiveUser(User*);
private:
    User* activeUser;
};
