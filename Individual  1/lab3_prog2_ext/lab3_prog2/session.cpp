#include "session.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int Session::seed = 0;

Session::Session(Student& innerStudent) : incomeStudent(&innerStudent)
{

}

void Session::initialize()
{
	srand(seed++);
    valueExam = new int[countExam];
	for (int i(0); i < countExam; i++)
	{
		
		*(valueExam + i) = rand() % 4 + 2;
	}
	cout << endl << endl;

	score = initMidSessionScore();
}

void Session::getResultSession()
{
	cout << incomeStudent->getfio() << endl;
	cout << "Value session: " << score << endl;

	for (int row(0); row < countExam; row++)
	{
		cout << row + 1 << " Exam : " << *(valueExam + row) << endl;
	}
}

double Session::getScoreSession()
{
	return score;
}

Session::~Session()
{
	delete[] valueExam;
}

void Session::SetStudentScore()
{
	if (incomeStudent->getscore() == 0.0)
	{
		incomeStudent->setscore(getScoreSession());
	}
	else
	{
		incomeStudent->setscore((getScoreSession() + incomeStudent->getscore()) / 2);
	}
}

double Session::initMidSessionScore()
{
	double ouputScore = 0.0;
	for (int i(0); i < countExam; i++)
	{
		ouputScore += *(valueExam + i);
	}
	return ouputScore / countExam;
}