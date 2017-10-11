#include "AdapterClass.h"



AdapterClass::AdapterClass()
{
}


AdapterClass::~AdapterClass()
{
}


std::string AdapterClass::format()
{
	std::string outstring = "its pretty class print: ";
	std::cout << "\n\nits pretty print: ";

	for (int i = 0; i < countCards; i++)
	{
		std::cout << "/" << cards[i].getsCard() << "/ ";
	}
	return outstring;
}