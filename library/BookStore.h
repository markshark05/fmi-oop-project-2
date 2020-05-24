#pragma once
#include <vector>
#include "Book.h"
#include <functional>

class BookStore
{
public:
    using filterFunc = std::function<bool(const Book&)>;
    using sortFunc = std::function<int(const Book&, const Book&)>;
    void Add(const Book& book);
    Book* GetById(unsigned int id);
    std::vector<Book*> Query(filterFunc filterF, sortFunc sortF);
    void RemoveById(unsigned int id);

private:
    std::vector<Book*> books;
};
