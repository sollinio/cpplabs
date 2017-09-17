#include "lecturer.h"



Lecturer::Lecturer()
{
}


Lecturer::~Lecturer()
{
	delete position;
}


double Lecturer::calculate()
{
	int salary =  5000;

	switch (sciencegegree)
	{
	case ScienceDegree::Candidate:
		salary += 700;
		break;
	case ScienceDegree::Doctor:
		salary += 1200;
		break;
	default:
		break;
	}

	switch (sciencerank)
	{
	case ScienceRank::Docent:
		salary += 2200;
		break;
	case ScienceRank::Professors:
		salary += 3500;
		break;
	default:
		break;
	}

	int tmp_experience = getexperience();

	while (tmp_experience >= 5)
	{
		salary += 700;
		tmp_experience -= 5;
	}

	return salary;
}

int Lecturer::getdtworkyear()
{
	return dtwork.tm_year;
}

int Lecturer::getexperience()
{
	return experience;
}

ScienceRank Lecturer::getsciencerank()
{
	return sciencerank;
}

ScienceDegree Lecturer::getsciencegegree()
{
	return sciencegegree;
}

char* Lecturer::getposition()
{
	return position;
}


void Lecturer::setdtworkyear(int inneryear)
{
	dtwork.tm_year = inneryear;
}

void Lecturer::setposition(char* innerposition)
{
	position = innerposition;
}

void Lecturer::setsciencerank(ScienceRank innerrank)
{
	sciencerank = innerrank;
}

void Lecturer::setsciencegegree(ScienceDegree innerdegree)
{
	sciencegegree = innerdegree;
}

void Lecturer::setexperience(int inner_exp)
{
	experience = inner_exp;
}

