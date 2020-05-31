#pragma once
#include "User.h"

/**
 * @brief Represents an abstract user context\n 
 * Allows the active user to be queried and switced
 * 
 */
class AuthorizeContext
{
private:
    User* activeUser;
public:
    /**
     * @brief Construct a new AuthorizeContext object
     * 
     */
    AuthorizeContext();
    /**
     * @brief Get the ActiveUser
     * 
     * @return const User* nullptr if no active user
     */
    const User* getActiveUser() const;
    /**
     * @brief Set the Active User object
     * 
     */
    void setActiveUser(User*);
};
