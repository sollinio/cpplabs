#pragma once

#include "Book.h"

class BookFinder
{
	int start;
	int end;
public:
	bool BookFinder::operator()(Book* b1);

	BookFinder(int start, int end);
	~BookFinder();
};

