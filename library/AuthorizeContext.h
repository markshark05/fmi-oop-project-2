#pragma once
#include "User.h"
class AuthorizeContext
{
public:
    const User* getActiveUser() const;
    void setActiveUser(User*);
private:
    User* activeUser;
};

