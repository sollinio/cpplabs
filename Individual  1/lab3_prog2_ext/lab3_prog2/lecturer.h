#pragma once

#include "person.h"
#include "Enum.h"
#include "ISalaryCalculation.h"

class Lecturer : public Person, public ISalaryCalculation
{
private:
	ScienceDegree sciencegegree;
	ScienceRank sciencerank;
	int experience;
	char* position;
	tm dtwork;
public:

	double calculate();

	void setsciencerank(ScienceRank innerrank);
	void setsciencegegree(ScienceDegree innerdegree);
	void setexperience(int inner_exp);
	void setdtworkyear(int setdtworkyear);
	void setposition(char* innerposition);

	char* getposition();
	int getdtworkyear();
	int getexperience();
	ScienceRank getsciencerank();
	ScienceDegree getsciencegegree();

	Lecturer();
	~Lecturer();
};

