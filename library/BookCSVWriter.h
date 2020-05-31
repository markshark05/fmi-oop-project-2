#pragma once
#include "CSVWriter.h"
#include "Book.h"

/**
 * @brief Represents a csv reader that can write a Book to file
 * 
 */
class BookCSVWriter
{
private:
    CSVWriter* csvWriter;
public:
    /**
     * @brief Construct a new BookCSVWriter with a regular CSV writer
     * 
     * @param csvWriter 
     */
    BookCSVWriter(CSVWriter& csvWriter);
    /**
     * @brief writes a Book to the file
     * 
     * @param out the stream to write to
     * @param book the Book to be written
     */
    void writeCSVBook(std::ostream& out, const Book& book);
};
