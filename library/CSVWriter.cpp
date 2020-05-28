#include "CSVWriter.h"

void CSVWriter::writeCSV(std::ostream& out, const std::vector<std::vector<std::string>>& csv)
{
    for (const std::vector<std::string>& row : csv)
    {
        writeCSVRow(out, row);
        out << std::endl;
    }
}

void CSVWriter::writeCSVRow(std::ostream& out, const std::vector<std::string>& csvRow)
{
    bool firstField = true;
    for (const std::string& field : csvRow)
    {
        if (!firstField)
        {
            out << ',';
        }
        firstField = false;
        
        bool quoted{ false };
        for (const char& c : field)
        {
            if (c == ',' || c == '"')
            {
                quoted = true;
                break;
            }
        }

        if (quoted) out << '"';
        for (const char& c : field)
        {
            if (c == '"') out << '"';
            out << c;
        }
        if (quoted) out << '"';
    }
}
