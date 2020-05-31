#pragma once
#include "CSVWriter.h"
#include "User.h"

/**
 * @brief Represents a csv reader that can write a User to file
 * 
 */
class UserCSVWriter
{
private:
    CSVWriter* csvWriter;
public:
    /**
     * @brief Construct a new UserCSVWriter with a regular CSV writer
     * 
     * @param csvWriter 
     */
    UserCSVWriter(CSVWriter& csvWriter);
    /**
     * @brief writes a User to the file
     * 
     * @param out the stream to write to
     * @param user the User to be written
     */
    void writeCSVUser(std::ostream& out, const User& user);
};
