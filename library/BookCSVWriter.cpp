#include "BookCSVWriter.h"

BookCSVWriter::BookCSVWriter(CSVWriter& csvWriter) :
    csvWriter(&csvWriter)
{
}

void BookCSVWriter::writeCSVBook(std::ostream& out, const Book& book)
{
    std::vector<std::string> fields;
    fields.push_back(std::to_string(book.getId()));
    fields.push_back(book.getTitle());
    fields.push_back(book.getAuthor());
    fields.push_back(book.getDescription());
    fields.push_back(book.getGenre());
    fields.push_back(std::to_string(book.getYear()));
    fields.push_back(std::to_string(book.getRating()));

    std::string tags_str;
    for (const std::string& t : book.getTags())
    {
        tags_str += t;
        tags_str += " ";
    }
    fields.push_back(tags_str);

    csvWriter->writeCSVRow(out, fields);
}
