#include "CSVReader.h"

std::vector<std::vector<std::string>> CSVReader::readCSV(std::istream& in)
{
    std::vector<std::vector<std::string>> table;
    std::string row;
    while (std::getline(in, row))
    {
        std::istringstream rowStream{ row };
        std::vector<std::string> fields = readCSVRow(rowStream);
        table.push_back(fields);
    }

    return table;
}

std::vector<std::string> CSVReader::readCSVRow(std::istream& rowstream)
{
    CSVState state = CSVState::UnquotedField;
    std::vector<std::string> fields{ "" };
    unsigned int field_i = 0;
    char c;
    while(rowstream.get(c))
    {
        switch (state)
        {
        case CSVState::UnquotedField:
            switch (c)
            {
            case ',':
                fields.push_back(""); field_i++;
                break;
            case '"': state = CSVState::QuotedField;
                break;
            default: fields[field_i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedField:
            switch (c)
            {
            case '"': state = CSVState::QuotedQuote;
                break;
            default: fields[field_i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedQuote:
            switch (c)
            {
            case ',':
                fields.push_back(""); field_i++;
                state = CSVState::UnquotedField;
                break;
            case '"':
                fields[field_i].push_back('"');
                state = CSVState::QuotedField;
                break;
            default:
                state = CSVState::UnquotedField;
                break;
            }
            break;
        }
    }

    return fields;
}
