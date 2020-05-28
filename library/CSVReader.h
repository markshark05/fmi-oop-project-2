#pragma once
#include <sstream>
#include <string>
#include <vector>

class CSVReader
{
private:
    enum class CSVState
    {
        UnquotedField,
        QuotedField,
        QuotedQuote
    };
public:
    std::vector<std::vector<std::string>> readCSV(std::istream& in);
    std::vector<std::string> readCSVRow(std::istream& row);
};

