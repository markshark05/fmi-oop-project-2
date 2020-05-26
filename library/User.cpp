#include "User.h"

User::User() :
    isAdmin(false)
{
}

std::string User::getUsername() const
{
    return username;
}

void User::setUsername(const std::string& value)
{
    username = value;
}

std::string User::getPassword() const
{
    return password;
}

void User::setPassword(const std::string& value)
{
    password = value;
}

bool User::getIsAdmin() const
{
    return isAdmin;
}

void User::setIsAdmin(bool value)
{
    isAdmin = value;
}
