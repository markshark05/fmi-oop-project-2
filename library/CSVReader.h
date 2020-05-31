#pragma once
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief repsents a csv reader
 * splits lines by comma and adds quotes where necessary
 * 
 */
class CSVReader
{
private:
    enum class CSVState
    {
        Initial,
        Quoted,
        QuotedQuote
    };
public:
    /**
     * @brief performs the csv parse
     * 
     * @param in the stream to read from
     * @return std::vector\<std::string\> the data
     */
    std::vector<std::string> readCSVRow(std::istream& in);
};
