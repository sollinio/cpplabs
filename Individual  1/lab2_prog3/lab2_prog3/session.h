#pragma once
#include "student.h"

class Session
{
private:
	Student* incomeStudent;
	double score;
	int countExam = 4;
	int* valueExam;
	static int seed;
	double initMidSessionScore();
public:
	Session(Student& innerStudent);
	void initialize();
	void getResultSession();
	double getScoreSession();
	void SetStudentScore();
	


	static int countsession;

	~Session();
};

