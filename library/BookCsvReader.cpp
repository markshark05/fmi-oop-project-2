#include "BookCSVReader.h"

BookCSVReader::BookCSVReader(CSVReader& csvReader) :
    csvReader(&csvReader)
{
}

bool BookCSVReader::readCsvBook(std::istream& in, Book& book)
{
    std::vector<std::string> fields = csvReader->readCSVRow(in);
    if (fields.size() != 0 && fields.size() != 8) return false;

    int i{ 0 };
    book.setId(std::stoi(fields[i++]));
    book.setTitle(fields[i++]);
    book.setAuthor(fields[i++]);
    book.setDescription(fields[i++]);
    book.setGenre(fields[i++]);
    book.setYear(std::stoi(fields[i++]));
    book.setRating(std::stof(fields[i++]));

    std::istringstream tags_str{ fields[i++] };
    std::string tag;
    std::vector<std::string> tags;
    while (tags_str >> tag)
    {
        tags.push_back(tag);
    }
    book.setTags(tags);

    return true;
}
