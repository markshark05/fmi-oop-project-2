#pragma once

#include <string>
#include <vector>
#include <ostream>

class Book
{
private:
    std::string author;
    std::string title;
    std::string genre;
    std::string description;
    std::vector<std::string> tags;
    int year;
    float rating;
    unsigned int id;
public:
    std::string getAuthor() const;
    void setAuthor(const std::string& value);

    std::string getTitle() const;
    void setTitle(const std::string& value);

    std::string getGenre() const;
    void setGenre(const std::string& value);

    std::string getDescription() const;
    void setDescription(const std::string& value);

    unsigned int getYear() const;
    void setYear(unsigned int value);

    std::vector<std::string> getTags() const;
    void setTags(const std::vector<std::string>& value);

    float getRating() const;
    void setRating(float value);

    unsigned int getId() const;
    void setId(unsigned int value);

    std::ostream& print_summary(std::ostream& out) const;
    std::ostream& print_detailed(std::ostream& out) const;
};
