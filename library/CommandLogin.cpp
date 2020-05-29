#include "CommandLogin.h"

CommandLogin::CommandLogin(AuthorizeContext& auth, UserStore& userStore) :
    Command("login", 0, "login [<username>] [<passowrd>] - loggs in existing user"),
    auth(&auth),
    userStore(&userStore)
{
}

bool CommandLogin::authorize()
{
    return !auth->getActiveUser();
}

void CommandLogin::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string username{ args.size() > 0 ? args[0] : promptLine(in, out, "Username") };
    const std::string password{ args.size() > 1 ? args[1] : promptLine(in, out, "Password") };

    User* user = userStore->getByUsername(username);
    if (user && user->getPassword() == password)
    {
        auth->setActiveUser(user);
        out << "Welcome, " << username << "!" << std::endl;
        return;
    }

    out << "Invalid login details" << std::endl;
}
