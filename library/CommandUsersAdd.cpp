#include "CommandUsersAdd.h"

CommandUsersAdd::CommandUsersAdd(AuthorizeContext const& auth, UserStore& userStore) :
    Command("users_add", 2, "users add <user> <password> - adds a new user"),
    auth(&auth),
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

    userStore->Add(user);
}
