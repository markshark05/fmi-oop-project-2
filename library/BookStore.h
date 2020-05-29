#pragma once
#include <vector>
#include "Book.h"
#include <functional>
#include "BookCsvReader.h"
#include "BookCSVWriter.h"

class BookStore
{
private:
    unsigned int AUTO_INCREMENT_DEFAULT{ 1 };
    
    BookCsvReader* reader;
    BookCSVWriter* writer;

    unsigned int auto_increment;
    std::vector<Book*> books;
public:
    using filterFunc = std::function<bool(const Book&)>;
    using sortFunc = std::function<bool(Book* const&, Book* const&)>;

    BookStore(BookCsvReader& reader, BookCSVWriter& writer);
    BookStore(const BookStore& other);
    ~BookStore();
    BookStore& operator = (const BookStore& other);
    void swap(BookStore& a, BookStore& b);

    void Add(const Book& book);
    Book* GetById(unsigned int id);
    std::vector<Book*> GetAll();
    std::vector<Book*> GetFiltered(filterFunc filterF);
    std::vector<Book*> GetSorted(sortFunc sortF);
    void RemoveById(unsigned int id);

    bool load(const std::string& fileName);
    bool save(const std::string& fileName);
private:
    std::vector<Book*> Query(filterFunc filterF, sortFunc sortF);
};
