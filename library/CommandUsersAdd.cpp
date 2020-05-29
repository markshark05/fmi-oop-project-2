#include "CommandUsersAdd.h"

CommandUsersAdd::CommandUsersAdd(AuthorizeContext const& auth, const FileContext& fileCtx, UserStore& userStore) :
    Command("users_add", 2, "users add <user> <password> - adds a new user"),
    auth(&auth),
    fileCtx(&fileCtx),
    userStore(&userStore)
{
}

bool CommandUsersAdd::authorize()
{
    return auth->getActiveUser() && auth->getActiveUser()->getIsAdmin();
}

void CommandUsersAdd::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& username = args[0];
    const std::string& password = args[1];

    User user;
    user.setUsername(username);
    user.setPassword(password);

    if (userStore->add(user) && 
        userStore->save(*fileCtx->getActiveFile()))
    {
        out << "User added and saved." << std::endl;
        return;
    }

    out << "Failed to add user." << std::endl;
}
