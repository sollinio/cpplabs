#include "BookFinder.h"



BookFinder::BookFinder(int i_start, int i_end) : start(i_start), end(i_end) { }
BookFinder::~BookFinder() { }

bool BookFinder::operator()(Book* b1)
{
	return (b1->getyearreleasebook() > start && b1->getyearreleasebook() < end);
}