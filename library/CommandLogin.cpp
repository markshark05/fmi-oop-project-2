#include "CommandLogin.h"

CommandLogin::CommandLogin(AuthorizeContext& auth, UserStore& userStore) :
    Command("login", 2, "login <interactive>"),
    auth(auth),
    userStore(userStore)
{
}

bool CommandLogin::authorize()
{
    return !auth.getActiveUser();
}

void CommandLogin::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& username = args[0];
    const std::string& password = args[1];

    if (auth.getActiveUser())
    {
        out << "You are already logged in." << std::endl;
        return;
    }

    User* user = userStore.getByUsername(username);
    if (user && user->getPassword() == password)
    {
        auth.setActiveUser(user);
        out << "Welcome, " << username << "!" << std::endl;
        return;
    }

    out << "Invalid login details" << std::endl;
}
