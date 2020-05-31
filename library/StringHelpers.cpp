#include <algorithm>
#include <sstream>
#include "StringHelpers.h"

std::string StringHelpers::join(const std::vector<std::string>& strings, char separator)
{
    return join(strings, separator, 0, strings.size());
}

std::string StringHelpers::join(const std::vector<std::string>& strings, char separator, size_t start)
{
    return join(strings, separator, start, strings.size());
}

std::string StringHelpers::join(const std::vector<std::string>& strings, char separator, size_t start, size_t end)
{
    start = std::max(std::min(strings.size(), start), rsize_t(0));
    end = std::max(std::min(strings.size(), end), size_t(0));

    if (end - start <= 0)
    {
        return "";
    }

    std::ostringstream res;
    res << strings[start];
    for (size_t i = start + 1; i < end; i++)
    {
        res << separator << strings[i];
    }

    return res.str();
}

int StringHelpers::icompare(const std::string& a, const std::string& b)
{
    for (size_t i = 0; i < a.length() && i < b.length(); i++)
    {
        int comp = icompare(a[i], b[i]);
        if (comp != 0)
        {
            return comp;
        }
    }

    return a.length() - b.length();
}

int StringHelpers::icompare(const char c1, const char c2)
{
    const char c1_lower = std::tolower(c1);
    const char c2_lower = std::tolower(c2);

    return c1_lower - c2_lower;
}
