#pragma once
#include "CSVReader.h"
#include "Book.h"

class BookCsvReader
{
private:
    CSVReader* csvReader;
public:
    BookCsvReader(CSVReader& csvReader);
    bool readCsvBook(std::istream& in, Book& book);
};
