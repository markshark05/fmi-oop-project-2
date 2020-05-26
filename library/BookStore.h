#pragma once
#include <vector>
#include "Book.h"
#include <functional>

class BookStore
{
public:
    using filterFunc = std::function<bool(const Book&)>;
    using sortFunc = std::function<bool(Book* const&, Book* const&)>;

    BookStore();
    void Add(const Book& book);
    Book* GetById(unsigned int id);
    std::vector<Book*> GetAll();
    std::vector<Book*> GetFiltered(filterFunc filterF);
    std::vector<Book*> GetSorted(sortFunc sortF);
    void RemoveById(unsigned int id);

private:
    std::vector<Book*> Query(filterFunc filterF, sortFunc sortF);

    unsigned int auto_increment;
    std::vector<Book*> books;
};
