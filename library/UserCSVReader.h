#pragma once
#include "User.h"
#include "CSVReader.h"

/**
 * @brief Represents a csv reader that can parse a User from file
 * 
 */
class UserCSVReader
{
private:
    CSVReader* csvReader;
public:
    /**
     * @brief Construct a new UserCSVReader with a regular CSVReader
     * 
     * @param csvReader 
     */
    UserCSVReader(CSVReader& csvReader);
        /**
     * @brief Performs the read
     * 
     * @param in the stream to read from
     * @param user the output User
     * @return true weather the row is a valid user
     * @return false otherwise
     */
    bool readCSVUser(std::istream& in, User& user);
};
