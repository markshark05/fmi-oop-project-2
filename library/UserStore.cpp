#include <fstream>
#include "UserStore.h"

UserStore::UserStore(UserCSVReader& reader, UserCSVWriter& writer) :
    reader(&reader),
    writer(&writer)
{
}

void UserStore::Add(const User& user)
{
    if (!getByUsername(user.getUsername()))
    {
        users.push_back(new User(user));
    }
}

User* UserStore::getByUsername(const std::string& username)
{
    for (User* const& u : users)
    {
        if (u->getUsername() == username)
        {
            return u;
        }
    }

    return nullptr;
}

void UserStore::RemoveByUsername(const std::string& username)
{
    for (auto i = users.begin(); i != users.end(); i++)
    {
        if ((*i)->getUsername() == username)
        {
            users.erase(i);
            return;
        }
    }
}

bool UserStore::load(const std::string& fileName)
{
    std::fstream file{ fileName, std::ios::in | std::ios::out | std::fstream::app };
    if (!file)
    {
        return false;
    }

    for (User*& u : users) delete u;
    users.clear();

    User user;
    while (reader->readCSVUser(file, user))
    {
        Add(user);
    }

    if (users.empty())
    {
        User defaultUser;
        defaultUser.setUsername("admin");
        defaultUser.setPassword("i<3c++");
        defaultUser.setIsAdmin(true);

        Add(defaultUser);
    }

    return true;
}

bool UserStore::save(const std::string& fileName)
{
    std::ofstream file{ fileName, std::ios::trunc };
    if (!file)
    {
        return false;
    }

    for (User*& u : users)
    {
        writer->writeCSVUser(file, *u);
    }

    return true;
}
