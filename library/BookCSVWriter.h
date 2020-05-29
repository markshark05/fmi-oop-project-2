#pragma once
#include "CSVWriter.h"
#include "Book.h"

class BookCSVWriter
{
private:
    CSVWriter* csvWriter;
public:
    BookCSVWriter(CSVWriter& csvWriter);
    void writeCSVBook(std::ostream& out, const Book& book);
};
