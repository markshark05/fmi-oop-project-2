#pragma once
#include "CSVReader.h"
#include "Book.h"

class BookCSVReader
{
private:
    CSVReader* csvReader;
public:
    BookCSVReader(CSVReader& csvReader);
    bool readCsvBook(std::istream& in, Book& book);
};
