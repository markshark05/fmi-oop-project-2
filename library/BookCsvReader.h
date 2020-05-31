#pragma once
#include "CSVReader.h"
#include "Book.h"

/**
 * @brief Represents a csv reader that can parse a Book from file
 * 
 */
class BookCSVReader
{
private:
    CSVReader* csvReader;
public:
    /**
     * @brief Construct a new BookCSVReader with a regular CSVReader
     * 
     * @param csvReader 
     */
    BookCSVReader(CSVReader& csvReader);
    /**
     * @brief Performs the read
     * 
     * @param in the stream to read from
     * @param book the output Book
     * @return true weather the row is a valid book
     * @return false otherwise
     */
    bool readCsvBook(std::istream& in, Book& book);
};
