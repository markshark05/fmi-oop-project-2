#pragma once
#include "Command.h"
#include "AuthorizeContext.h"

/**
 * @brief logout - loggs out current user
 * 
 */
class CommandLogout :
    public Command
{
private:
    AuthorizeContext* auth;
public:
    /**
     * @brief Construct a new CommandLogout object
     * 
     * @param auth the AuthorizeContext used to authorize the user and switch them
     */
    CommandLogout(AuthorizeContext& auth);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
