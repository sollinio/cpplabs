#pragma once
#include <string>
#include "Book.h"

class BookSorter
{
public:
	bool operator()(Book* s1, Book* s2);
	BookSorter();
	~BookSorter();
};

