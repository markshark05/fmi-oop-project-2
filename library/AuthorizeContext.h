#pragma once
#include "User.h"
class AuthorizeContext
{
private:
    User* activeUser;
public:
    AuthorizeContext();
    const User* getActiveUser() const;
    void setActiveUser(User*);
};
