#pragma once

#include <string>
#include <ctime>

class Book
{
	std::string name;
	std::string author;
	tm dtreleasebook;

public:

	std::string getname();
	std::string getauthor();
	int getyearreleasebook();

	Book(std::string name, std::string author, int year);
	~Book();
};

