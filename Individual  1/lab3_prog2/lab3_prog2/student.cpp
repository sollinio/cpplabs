#include "student.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int Student::counterStudent = 0;

Student::Student()
{
	counterStudent++;
}

Student::Student(char* inner_fio, Gender inner_gender, int inner_birth_year, int inner_income_year, int inner_number_srb, double inner_score) :
	income_year(inner_income_year), number_srb(number_srb), score(inner_score)
{
	setbirthyear(inner_birth_year);
	setgender(inner_gender);
	setpfio(inner_fio);
	counterStudent++;
}

void Student::setincomeyear(int inner_income_year)
{
	income_year = inner_income_year;
}

void Student::setnumbersrb(int inner_number_srb)
{
	number_srb = inner_number_srb;
}

void Student::setscore(double inner_score)
{
	score = inner_score;
}

double Student::getscore()
{
	return score;
}

string Student::getstringnumber_srb()
{
	ostringstream ss;
	ss << number_srb;
	return ss.str();
}

void Student::serialize()
{
	string path = "data" + getstringnumber_srb() + ".txt";
	ofstream fout(path,ios_base::trunc);
	fout << getpfio() << ";" << getgender() << ";" << getbirthyear() << ";"
		<< income_year << ";" << number_srb << ";" << score << endl;
	fout.close();
}

void Student::serialize(string path) 
{ 
	ofstream fout(path, ios_base::out, ios_base::trunc);
	fout << getpfio() << ";" << getgender() << ";" << getbirthyear() << ";"
		<< income_year << ";" << number_srb << ";" << score << ";" << endl;
	fout.close();
}

void Student::deserialize()
{
	string path = "data" + getstringnumber_srb() + ".txt";
	ifstream fin(path,ios_base::in);
	char s[255];
	fin.getline(s,255);
	splitset(s);
}

void Student::deserialize(string path)
{
	ifstream fin(path, ios_base::in);
	char s[255];
	fin.getline(s, 255);
	splitset(s);
}

void Student::splitset(char* str)
{
	char splitchar = ';';
	char* pointStart = str;
	char* pointNow = str;
	char* pointEnd = str;
	int countMark = 0;

	for (int i = 0; i < 255; i++)
	{
		if (*(pointEnd++) == splitchar)
		{
			switch (countMark++)
			{
			case 0:
				setpfio((char*)getsplitstr(pointNow, (pointEnd - pointNow)));
				break;
			case 1:
				setgender((Gender)((int)getsplitstr(pointNow, (pointEnd - pointNow))));
				break;
			case 2:
				setbirthyear((int)getsplitstr(pointNow, (pointEnd - pointNow)));
				break;
			case 3:
				setincomeyear((int)getsplitstr(pointNow, (pointEnd - pointNow)));
				break;
			case 4:
				setnumbersrb((int)getsplitstr(pointNow, (pointEnd - pointNow)));
				break;
			case 5:
				setscore(atof((char*)getsplitstr(pointNow, (pointEnd - pointNow))));
				break;
			default:
				break;
			}
			pointNow = pointEnd;
		}
	}
}

char Student::getsplitstr(char* start, int count )
{
	char return_tmp[255];
	for (int i = 0; i < count; i++)
	{
		return_tmp[i] = *(start + i);
	}
	return_tmp[count - 1] = '\0';
	return *return_tmp;
}

Student::~Student()
{
	counterStudent--;
}

double Student::calculate()
{
	if (getscore() > 4.5)
		return 1000;
	else
		return 700;
}