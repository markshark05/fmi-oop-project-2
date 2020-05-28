#pragma once
#include "CSVReader.h"
#include "Book.h"

class BookCsvReader
{
public:
    BookCsvReader(CSVReader& csvReader);
    bool readCsvBook(std::istream& in, Book& book);
private:
    CSVReader& csvReader;
};
