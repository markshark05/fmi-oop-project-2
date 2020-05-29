#pragma once
#include <vector>
#include "User.h"

class UserStore
{
private:
    std::vector<User*> users;
public:
    UserStore();
    void Add(const User& user);
    User* getByUsername(const std::string& username);
    void RemoveByUsername(const std::string& username);
};
