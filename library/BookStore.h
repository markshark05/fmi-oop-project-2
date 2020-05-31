#pragma once
#include <vector>
#include "Book.h"
#include <functional>
#include "BookCSVReader.h"
#include "BookCSVWriter.h"

/**
 * @brief Represents an abstract Book storage\n 
 * Provides methods for CRUD operations as well as persist and load
 * 
 */
class BookStore
{
private:
    unsigned int AUTO_INCREMENT_DEFAULT{ 1 };
    
    BookCSVReader* reader;
    BookCSVWriter* writer;

    unsigned int auto_increment;
    std::vector<Book*> books;
public:
    /**
     * @brief The signature of the filter function
     * 
     */
    using filterFunc = std::function<bool(Book* const&)>;
    /**
     * @brief The signature of the sort function
     * 
     */
    using sortFunc = std::function<bool(Book* const&, Book* const&)>;

    /**
     * @brief Construct a new BookStore with a reader and writer
     * 
     * @param reader the storage reader
     * @param writer the storage writer
     */
    BookStore(BookCSVReader& reader, BookCSVWriter& writer);
    /**
     * @brief Construct a new BookStore object from other
     * 
     * @param other 
     */
    BookStore(const BookStore& other);
    /**
     * @brief Destroy the BookStore object
     * 
     */
    ~BookStore();
    /**
     * @brief Assign BookStore object
     * 
     * @param other 
     * @return BookStore& 
     */
    BookStore& operator = (const BookStore& other);
    /**
     * @brief Swaps the internal data of two BookStore
     * 
     * @param a the first object
     * @param b the second object
     */
    void swap(BookStore& a, BookStore& b);

    /**
     * @brief Add a copy of the Book to the BookStore
     * 
     * @param book reference to the Book
     */
    void add(const Book& book);
    /**
     * @brief Retrieve a Book by its id
     * 
     * @param id the id of the Book
     * @return Book* nullptr if not found
     */
    Book* getById(unsigned int id);
    /**
     * @brief Retrieve all books in the store
     * 
     * @return std::vector\<Book*\> 
     */
    std::vector<Book*> getAll();
    /**
     * @brief Get books filtered by filterF
     * 
     * @param filterF the filter function
     * @return std::vector\<Book*\> 
     */
    std::vector<Book*> getFiltered(filterFunc filterF);
    /**
     * @brief Get the books sorted by sortF
     * 
     * @param sortF the sort function
     * @return std::vector<Book*> 
     */
    std::vector<Book*> getSorted(sortFunc sortF);
    /**
     * @brief Removes a Book by its id
     * 
     * @param id the id of the Book
     * @return true if the book was found and removed
     * @return false otherwise
     */
    bool RemoveById(unsigned int id);

    /**
     * @brief Replace the in-memory BookStore from file
     * 
     * @param fileName 
     * @return true if the operation was succesful
     * @return false otherwise
     */
    bool load(const std::string& fileName);
    /**
     * @brief Saves the in-memory BookStore to a file
     * 
     * @param fileName 
     * @return true if the operation was succesful
     * @return false otherwise
     */
    bool save(const std::string& fileName);
private:
    std::vector<Book*> query(filterFunc filterF, sortFunc sortF);
};
