#include "Book.h"



Book::Book(std::string inner_name, std::string inner_author, int inner_year)
	: name(inner_name),author(inner_author)
{
	year = inner_year;
}


Book::~Book() {}

std::string Book::getname() const
{
	return name;
}

std::string Book::getauthor() const
{
	return author;
}

int Book::getyearreleasebook() const
{
	return year;
}

bool operator>(const Book b1, const Book b2)
{
	return (b1.getyearreleasebook() > b2.getyearreleasebook());
}
