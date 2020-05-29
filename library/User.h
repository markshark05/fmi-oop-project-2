#pragma once
#include <string>

class User
{
private:
    std::string username;
    std::string password;
    bool isAdmin;
public:
    User();
    std::string getUsername() const;
    void setUsername(const std::string& value);

    std::string getPassword() const;
    void setPassword(const std::string& value);

    bool getIsAdmin() const;
    void setIsAdmin(bool value);
};
