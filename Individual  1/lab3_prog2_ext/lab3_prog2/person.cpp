#include "person.h"


Person::Person()
{
}


Person::~Person()
{
	delete fio;
}

void Person::setpfio(char* innerfio)
{
	fio = innerfio;
}

void Person::setgender(Gender innergender)
{
	gender = innergender;
}

void Person::setposition(Position innerposition)
{
	position = innerposition;
}

void Person::setbirthyear(int inneryear)
{
	birth.tm_year = inneryear;
}
Position Person::getposition()
{
	return position;
}

Gender Person::getgender()
{
	return gender;
}

char* Person::getpfio()
{
	return fio;
}

int Person::getbirthyear()
{
	return birth.tm_year;
}

