#pragma once
#include <vector>
#include "User.h"

class UserStore
{
public:
    void Add(const User& user);
    User* getByUsername(std::string& username);
    void RemoveByUsername(std::string& username);
private:
    std::vector<User*> users;
};
