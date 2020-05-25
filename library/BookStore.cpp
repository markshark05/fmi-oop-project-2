#include <algorithm>
#include "BookStore.h"

BookStore::BookStore() :
    auto_increment(1)
{
}

void BookStore::Add(const Book& book)
{
    Book* newBook = new Book(book);
    newBook->setId(auto_increment++);

    books.push_back(newBook);
}

Book* BookStore::GetById(unsigned int id)
{
    for (Book* const& b : books)
    {
        if (b->getId() == id)
        {
            return b;
        }
    }

    return nullptr;
}

std::vector<Book*> BookStore::GetAll()
{
    return books;
}

std::vector<Book*> BookStore::GetFiltered(filterFunc filterF)
{
    return Query(filterF, nullptr);
}

std::vector<Book*> BookStore::GetSorted(sortFunc sortF)
{
    return Query(nullptr, sortF);
}

void BookStore::RemoveById(unsigned int id)
{
    for (auto i = books.begin(); i != books.end(); i++)
    {
        if ((*i)->getId() == id)
        {
            books.erase(i);
            return;
        }
    }
}

std::vector<Book*> BookStore::Query(filterFunc filterF, sortFunc sortF)
{
    std::vector<Book*> filtered;
    for (Book* const& b : books)
    {
        if (!filterF || filterF(*b))
        {
            filtered.push_back(b);
        }
    }

    if (sortF)
    {
        std::sort(filtered.begin(), filtered.end(), sortF);
    }
    
    return filtered;
}
