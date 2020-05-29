#include "UserCSVReader.h"

UserCSVReader::UserCSVReader(CSVReader& csvReader) :
    csvReader(&csvReader)
{
}

bool UserCSVReader::readCSVUser(std::istream& in, User& user)
{
    std::vector<std::string> fields = csvReader->readCSVRow(in);
    if (fields.size() != 0 && fields.size() != 3) return false;

    int i{ 0 };
    user.setUsername(fields[i++]);
    user.setPassword(fields[i++]);
    user.setIsAdmin(std::stoi(fields[i++]));

    return true;
}
