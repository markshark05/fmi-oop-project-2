#pragma once
#include <vector>
#include "User.h"
#include "UserCSVWriter.h"
#include "UserCSVReader.h"

class UserStore
{
private:
    UserCSVReader* reader;
    UserCSVWriter* writer;

    std::vector<User*> users;
public:
    UserStore(UserCSVReader& reader, UserCSVWriter& writer);
    
    void Add(const User& user);
    User* getByUsername(const std::string& username);
    void RemoveByUsername(const std::string& username);

    bool load(const std::string& fileName);
    bool save(const std::string& fileName);
};
