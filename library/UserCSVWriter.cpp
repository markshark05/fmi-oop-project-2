#include "UserCSVWriter.h"

UserCSVWriter::UserCSVWriter(CSVWriter& csvWriter) :
    csvWriter(&csvWriter)
{
}

void UserCSVWriter::writeCSVUser(std::ostream& out, const User& user)
{
    std::vector<std::string> fields;
    fields.push_back(user.getUsername());
    fields.push_back(user.getPassword());
    fields.push_back(std::to_string(user.getIsAdmin()));

    csvWriter->writeCSVRow(out, fields);
}
