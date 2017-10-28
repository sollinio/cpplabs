#include "BookSorter.h"



BookSorter::BookSorter() { }
BookSorter::~BookSorter() { }

bool BookSorter::operator()(Book* b1, Book* b2) 
{
	return b1->getname() < b2->getname();
}