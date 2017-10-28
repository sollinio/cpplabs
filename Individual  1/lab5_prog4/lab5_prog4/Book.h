#pragma once

#include <string>
#include <ctime>

class Book
{
	int year;
	std::string name;
	std::string author;

public:

	std::string getname() const;
	std::string getauthor() const;
	int getyearreleasebook() const;
	Book(std::string name, std::string author, int year);
	~Book();
};

