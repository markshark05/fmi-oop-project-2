#include "CommandUsersRemove.h"

CommandUsersRemove::CommandUsersRemove(AuthorizeContext const& auth, const FileContext& fileCtx, UserStore& userStore) :
    Command("users_remove", 1, "users remove <user> - removes an existing user"),
    auth(&auth),
    fileCtx(&fileCtx),
    userStore(&userStore)
{
}

bool CommandUsersRemove::authorize()
{
    return auth->getActiveUser() && auth->getActiveUser()->getIsAdmin();
}

void CommandUsersRemove::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& username = args[0];

    if (userStore->removeByUsername(username) &&
        userStore->save(*fileCtx->getActiveFile()))
    {
        out << "User removed and saved." << std::endl;
        return;
    }

    out << "Failed to remove user." << std::endl;
}
