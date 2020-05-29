#pragma once
#include "CSVWriter.h"
#include "User.h"

class UserCSVWriter
{
private:
    CSVWriter* csvWriter;
public:
    UserCSVWriter(CSVWriter& csvWriter);
    void writeCSVUser(std::ostream& out, const User& user);
};
