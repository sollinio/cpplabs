#pragma once
#include "Enum.h"

#include <time.h>

class Person
{
private:
	char* fio;
	Gender gender;
	tm birth;
	Position position;

public:
	Person();
	virtual ~Person();

	void setpfio(char* innerfio);
	void setgender(Gender innergender);
	void setposition(Position innerposition);
	void setbirthyear(int inneryear);

	char* getpfio();
	Gender getgender();
	Position getposition();
	int getbirthyear();

};

