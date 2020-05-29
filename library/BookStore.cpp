#include <algorithm>
#include <fstream>
#include "BookStore.h"

BookStore::BookStore(BookCSVReader& reader, BookCSVWriter& writer) :
    auto_increment(AUTO_INCREMENT_DEFAULT),
    reader(&reader),
    writer(&writer)
{
}

BookStore::BookStore(const BookStore& other) :
    auto_increment(other.auto_increment),
    reader(other.reader),
    writer(other.writer)
{
    books.reserve(other.books.size());
    for (Book* const& b : other.books)
    {
        books.push_back(new Book(*b));
    }
}

BookStore::~BookStore()
{
    for (Book*& b : books) delete b;
}

BookStore& BookStore::operator=(const BookStore& other)
{
    BookStore copy{ other };
    swap(*this, copy);
    return *this;
}

void BookStore::swap(BookStore& a, BookStore& b)
{
    std::swap(a.reader, b.reader);
    std::swap(a.writer, b.writer);
    std::swap(a.auto_increment, b.auto_increment);
    std::swap(a.books, b.books);
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

bool BookStore::load(const std::string& fileName)
{
    std::fstream file{ fileName, std::ios::in | std::ios::out | std::fstream::app };
    if (!file)
    {
        return false;
    }

    for (Book*& b : books) delete b;
    books.clear();
    auto_increment = AUTO_INCREMENT_DEFAULT;

    Book book;
    while (reader->readCsvBook(file, book))
    {
        books.push_back(new Book(book));
    }

    if (!books.empty())
    {
        auto_increment = books.back()->getId() + 1;
    }

    return true;
}

bool BookStore::save(const std::string& fileName)
{
    std::ofstream file{ fileName, std::ios::trunc };
    if (!file)
    {
        return false;
    }

    for (Book*& b : books)
    {
        writer->writeCSVBook(file, *b);
    }

    return true;
}

std::vector<Book*> BookStore::Query(filterFunc filterF, sortFunc sortF)
{
    std::vector<Book*> filtered;
    for (auto b : books)
    {
        if (!filterF || filterF(b))
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
