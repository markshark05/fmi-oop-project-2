#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "FileContext.h"
#include "UserStore.h"

/**
 * @brief users remove \<user\> - removes an existing user
 * 
 */
class CommandUsersRemove :
    public Command
{
private:
    const AuthorizeContext* auth;
    const FileContext* fileCtx;
    UserStore* userStore;
public:
    /**
     * @brief Construct a new CommandUsersRemove object
     * 
     * @param auth the AuthorizeContext to verify admin
     * @param fileCtx the User FileContext
     * @param userStore the UserStore to remove from
     */
    CommandUsersRemove(AuthorizeContext const& auth, const FileContext& fileCtx, UserStore& userStore);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
