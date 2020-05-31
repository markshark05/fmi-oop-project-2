#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "UserStore.h"

/**
 * @brief login [\<username\>] [\<passowrd\>] - loggs in existing user
 * 
 */
class CommandLogin :
    public Command
{
private:
    AuthorizeContext* auth;
    UserStore* userStore;
public:
    /**
     * @brief Construct a new CommandLogin object
     * 
     * @param auth the AuthorizeContext used to authorize the user and switch them
     * @param userStore the user store to be queried
     */
    CommandLogin(AuthorizeContext& auth, UserStore& userStore);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
