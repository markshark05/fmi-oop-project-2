#pragma once
#include "User.h"
#include "CSVReader.h"

class UserCSVReader
{
private:
    CSVReader* csvReader;
public:
    UserCSVReader(CSVReader& csvReader);
    bool readCSVUser(std::istream& in, User& user);
};
