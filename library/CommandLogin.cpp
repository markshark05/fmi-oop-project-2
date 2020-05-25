#include "CommandLogin.h"

CommandLogin::CommandLogin()
    :Command("login", 0, "login <interactive>")
{
}

bool CommandLogin::authorize(bool userIsLoggedIn, bool userIsAdmin)
{
    return true;
}

void CommandLogin::execute(std::ostream& out, const std::vector<std::string>& args)
{
}
