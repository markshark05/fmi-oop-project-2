#pragma once
#include <string>

/**
 * @brief Represents the application user
 * 
 */
class User
{
private:
    std::string username;
    std::string password;
    bool isAdmin;
public:
    /**
     * @brief Construct a new non-admin User with empty data
     * 
     */
    User();
    /**
     * @brief Get the Username
     * 
     */
    std::string getUsername() const;
    /**
     * @brief Set the Username
     * 
     */
    void setUsername(const std::string& value);

    /**
     * @brief Get the Password
     * 
     */
    std::string getPassword() const;
    /**
     * @brief Set the Password
     * 
     */
    void setPassword(const std::string& value);

    /**
     * @brief Get the IsAdmin
     * 
     */
    bool getIsAdmin() const;
    /**
     * @brief Set the IsAdmin
     * 
     */
    void setIsAdmin(bool value);
};
