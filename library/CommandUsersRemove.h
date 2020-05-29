#pragma once
#include "Command.h"
#include "AuthorizeContext.h"
#include "FileContext.h"
#include "UserStore.h"

class CommandUsersRemove :
    public Command
{
private:
    const AuthorizeContext* auth;
    const FileContext* fileCtx;
    UserStore* userStore;
public:
    CommandUsersRemove(AuthorizeContext const& auth, const FileContext& fileCtx, UserStore& userStore);
    bool authorize() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
