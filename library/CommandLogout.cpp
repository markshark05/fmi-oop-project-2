#include "CommandLogout.h"

CommandLogout::CommandLogout()
    :Command("logout", 0, "logout")
{
}

bool CommandLogout::authorize(bool userIsLoggedIn, bool userIsAdmin)
{
    return userIsLoggedIn;
}

void CommandLogout::execute(std::ostream& out, const std::vector<std::string>& args)
{
}
