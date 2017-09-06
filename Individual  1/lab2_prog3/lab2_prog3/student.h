#pragma once
#include <string>

enum Gender
{
	Man, Woman
};

class Student
{
private:
	char* fio;
	Gender gender;
	int birth_year;
	int income_year;
	int number_srb; // student record book
	double score;
	void splitset(char* str);
	char getsplitstr(char* start, int count);
public:
	void setfio(char* inner_fio);
	void setGender(Gender inner_gender);
	void setbirthyear(int inner_birth_year);
	void setincomeyear(int inner_birth_year);
	void setnumbersrb(int inner_birth_year);
	void setscore(double inner_score);

	double getscore();
	std::string getstringnumber_srb();
	char* getfio();

	void serialize();
	void serialize(const std::string path);
	void deserialize();
	void deserialize(const std::string path);

	static int counterStudent;

	Student();
	Student(char* inner_fio, Gender inner_gender, int inner_birth_year, int inner_income_year, int inner_number_srb, double inner_score);
	~Student();
};

