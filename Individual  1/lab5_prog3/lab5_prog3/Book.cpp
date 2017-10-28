#include "Book.h"



Book::Book(std::string inner_name, std::string inner_author, int inner_year)
	: name(inner_name),author(inner_author)
{
	dtreleasebook.tm_year = inner_year;
}


Book::~Book() {}

std::string Book::getname()
{
	return name;
}

std::string Book::getauthor()
{
	return author;
}

int Book::getyearreleasebook()
{
	return dtreleasebook.tm_year;
}