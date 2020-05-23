#pragma once

#include <string>

class User
{
public:
    User();
    std::string getUsername();
    void setUsername(const std::string& value);

    std::string getPassword();
    void setPassword(const std::string& value);

    bool getIsAdmin();
    void setIsAdmin(bool value);
private:
    std::string username;
    std::string password;
    bool isAdmin;
};
