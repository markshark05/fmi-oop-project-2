#pragma once
#include <vector>
#include <string>

/**
 * @brief Provides common string operations
 * 
 */
class StringHelpers
{
public:
    /**
     * @brief joins string with separator
     * 
     */
    static std::string join(const std::vector<std::string>& strings, char separator);
    /**
     * @brief joins string with separator starting at start
     * 
     */
    static std::string join(const std::vector<std::string>& strings, char separator, size_t start);
    /**
     * @brief joins string with separator starting at start and ending at end
     * 
     */
    static std::string join(const std::vector<std::string>& strings, char separator, size_t start, size_t end);
    /**
     * @brief compares strings ignoring case
     * 
     */
    static int icompare(const std::string& a, const std::string& b);
    /**
     * @brief comapres char ingoring case
     * 
     */
    static int icompare(const char c1, const char c2);
};
