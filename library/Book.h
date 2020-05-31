#pragma once

#include <string>
#include <vector>
#include <ostream>

/**
 * @brief Represents the Book entity
 * 
 */
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
    /**
     * @brief Construct a new Book with empty data
     * 
     */
    Book();

    /**
     * @brief Get the Author
     * 
     */
    std::string getAuthor() const;
    /**
     * @brief Set the Author
     * 
     */
    void setAuthor(const std::string& value);

    /**
     * @brief Get the Title
     * 
     */
    std::string getTitle() const;
    /**
     * @brief Set the Title
     * 
     */
    void setTitle(const std::string& value);

    /**
     * @brief Get the Genre
     * 
     */
    std::string getGenre() const;
    /**
     * @brief Set the Genre
     * 
     */
    void setGenre(const std::string& value);

    /**
     * @brief Get the Description
     * 
     */
    std::string getDescription() const;
    /**
     * @brief Set the Description object
     * 
     */
    void setDescription(const std::string& value);

    /**
     * @brief Get the Year object
     * 
     */
    unsigned int getYear() const;
    /**
     * @brief Set the Year object
     * 
     */
    void setYear(unsigned int value);

    /**
     * @brief Get the Tags object
     * 
     */
    std::vector<std::string> getTags() const;
    /**
     * @brief Set the Tags object
     * 
     */
    void setTags(const std::vector<std::string>& value);

    /**
     * @brief Get the Rating object
     * 
     */
    float getRating() const;
    /**
     * @brief Set the Rating object
     * 
     */
    void setRating(float value);

    /**
     * @brief Get the Id object
     * 
     */
    unsigned int getId() const;
    /**
     * @brief Set the Id object
     * 
     */
    void setId(unsigned int value);

    /**
     * @brief prints to out a one line summary of the obeject
     * 
     * @param out the output stream
     * @return std::ostream& 
     */
    std::ostream& print_summary(std::ostream& out) const;
    /**
     * @brief prints to out a one line summary of the obeject
     * 
     * @param out the output stream
     * @return std::ostream& 
     */
    std::ostream& print_sort_summary(std::ostream& out) const;
    /**
     * @brief prints to out all of the members in the object
     * 
     * @param out the output stream
     * @return std::ostream& 
     */
    std::ostream& print_detailed(std::ostream& out) const;
};
