#pragma once
#include <string>

#include "person.h"
#include "Enum.h"
#include "ISalaryCalculation.h"


class Student : public Person, public ISalaryCalculation
{

private:
	int income_year;
	int number_srb; // student record book
	double score;
	void splitset(char* str);
	char getsplitstr(char* start, int count);
public:
	void setincomeyear(int inner_birth_year);
	void setnumbersrb(int inner_birth_year);
	void setscore(double inner_score);

	double calculate();

	double getscore();
	std::string getstringnumber_srb();

	void serialize();
	void serialize(const std::string path);
	void deserialize();
	void deserialize(const std::string path);

	static int counterStudent;

	Student();
	Student(char* inner_fio, Gender inner_gender, int inner_birth_year, int inner_income_year, int inner_number_srb, double inner_score);
	~Student();

};

