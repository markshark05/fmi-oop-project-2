#pragma once

#include <string>
#include <vector>

class Book
{
public:
    std::string getAuthor();
    void setAuthor(const std::string& value);

    std::string getTitle();
    void setTitle(const std::string& value);

    std::string getGenre();
    void setGenre(const std::string& value);

    std::string getDescription();
    void setDescription(const std::string& value);

    unsigned int getYear();
    void setYear(unsigned int value);

    std::vector<std::string> getTags();
    void setTags(const std::vector<std::string>& value);

    float getRating();
    void setRating(float value);

    unsigned int getId();
    void setId(unsigned int value);
};
