#pragma once
#include "CSVWriter.h"
#include "Book.h"

class BookCSVWriter
{
public:
    BookCSVWriter(CSVWriter& csvWriter);
    void writeCSVBook(std::ostream& out, const Book& book);
private:
    CSVWriter& csvWriter;
};
