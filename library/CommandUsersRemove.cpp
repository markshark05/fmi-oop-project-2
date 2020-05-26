#include "CommandUsersRemove.h"

CommandUsersRemove::CommandUsersRemove(AuthorizeContext const& auth, UserStore& userStore) :
    Command("users_remove", 1, "users_remove <user>"),
    auth(auth),
    userStore(userStore)
{
}

bool CommandUsersRemove::authorize()
{
    return auth.getActiveUser() && auth.getActiveUser()->getIsAdmin();
}

void CommandUsersRemove::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& username = args[0];

    userStore.RemoveByUsername(username);
}
