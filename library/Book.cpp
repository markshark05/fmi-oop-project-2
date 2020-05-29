#include "Book.h"


Book::Book() :
    id(0),
    rating(0),
    year(1970)
{
}

std::string Book::getAuthor() const
{
    return author;
}

void Book::setAuthor(const std::string& value)
{
    author = value;
}

std::string Book::getTitle() const
{
    return title;
}

void Book::setTitle(const std::string& value)
{
    title = value;
}

std::string Book::getGenre() const
{
    return genre;
}

void Book::setGenre(const std::string& value)
{
    genre = value;
}

std::string Book::getDescription() const
{
    return description;
}

void Book::setDescription(const std::string& value)
{
    description = value;
}

unsigned int Book::getYear() const
{
    return year;
}

void Book::setYear(unsigned int value)
{
    year = value;
}

std::vector<std::string> Book::getTags() const
{
    return tags;
}

void Book::setTags(const std::vector<std::string>& value)
{
    tags = value;
}

float Book::getRating() const
{
    return rating;
}

void Book::setRating(float value)
{
    rating = value;
}

unsigned int Book::getId() const
{
    return id;
}

void Book::setId(unsigned int value)
{
    id = value;
}

std::ostream& Book::print_summary(std::ostream& out) const
{
    out
        << "Id: " << id << " "
        << "Title: " << title << " "
        << "Author: " << author << " "
        << "Genre: " << genre << " "
        << std::endl;

    return out;
}

std::ostream& Book::print_sort_summary(std::ostream& out) const
{
    out
        << "Id: " << id << " "
        << "Title: " << title << " "
        << "Author: " << author << " "
        << "Year: " << year << " "
        << "Rating: " << rating << " "
        << std::endl;

    return out;
}

std::ostream& Book::print_detailed(std::ostream& out) const
{
    out
        << "Id: " << id << std::endl
        << "Title: " << title << std::endl
        << "Author: " << author << std::endl
        << "Genre: " << genre << std::endl
        << "Year: " << year << std::endl
        << "Description: " << description << std::endl
        << "Rating: " << rating << std::endl
        << "Tags: ";
    
    for (const std::string& t : tags)
    {
        out << t << " ";
    }
    out << std::endl;
    
    return out;
}
