#include <algorithm>
#include <fstream>
#include "BookStore.h"

const unsigned int BookStore::AUTO_INCREMENT_START{ 1 };

BookStore::BookStore(BookCSVReader& reader, BookCSVWriter& writer) :
    auto_increment(AUTO_INCREMENT_START),
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

void BookStore::add(const Book& book)
{
    Book* newBook = new Book(book);
    newBook->setId(auto_increment++);

    books.push_back(newBook);
}

Book* BookStore::getById(unsigned int id)
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

std::vector<Book*> BookStore::getAll()
{
    return books;
}

std::vector<Book*> BookStore::getFiltered(filterFunc filterF)
{
    return query(filterF, nullptr);
}

std::vector<Book*> BookStore::getSorted(sortFunc sortF)
{
    return query(nullptr, sortF);
}

bool BookStore::RemoveById(unsigned int id)
{
    for (auto i = books.begin(); i != books.end(); i++)
    {
        if ((*i)->getId() == id)
        {
            books.erase(i);
            return true;
        }
    }
    return false;
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
    auto_increment = AUTO_INCREMENT_START;

    Book book;
    while (reader->readCsvBook(file, book))
    {
        auto_increment = book.getId();
        add(book);
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

std::vector<Book*> BookStore::query(filterFunc filterF, sortFunc sortF)
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
