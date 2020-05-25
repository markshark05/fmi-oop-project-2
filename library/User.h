#pragma once

#include <string>

class User
{
public:
    User();
    std::string getUsername() const;
    void setUsername(const std::string& value);

    std::string getPassword() const;
    void setPassword(const std::string& value);

    bool getIsAdmin() const;
    void setIsAdmin(bool value);
private:
    std::string username;
    std::string password;
    bool isAdmin;
};
