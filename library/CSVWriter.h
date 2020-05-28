#pragma once
#include <ostream>
#include <string>
#include <vector>

class CSVWriter
{
public:
    void writeCSV(std::ostream& out, const std::vector<std::vector<std::string>>& csv);
    void writeCSVRow(std::ostream& out, const std::vector<std::string>& csvRow);
};
