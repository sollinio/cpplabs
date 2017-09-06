#include "student.h"
#include "session.h"
#include <locale>

using namespace std;


void main()
{
	int countSession = 3;

	setlocale(LC_ALL,"Russian");

	Student group[3];

	//first
	group[0].setfio("Финолин Алексей Иванович");
	group[0].setbirthyear(1999);
	group[0].setnumbersrb(666123);
	group[0].setGender(Gender::Man);
	group[0].setincomeyear(2017);
	group[0].setscore(4.2);
	//second
	group[1].setfio("Хмельник Виктория Аркадиевна");
	group[1].setbirthyear(1998);
	group[1].setnumbersrb(666124);
	group[1].setGender(Gender::Woman);
	group[1].setincomeyear(2017);
	group[1].setscore(4.9);

	//third
	group[2].setfio("Копатыч Николай Федорович");
	group[2].setbirthyear(1997);
	group[2].setnumbersrb(666125);
	group[2].setGender(Gender::Man);
	group[2].setincomeyear(2017);
	group[2].setscore(3.6);

	Student* newStudent = new Student("Валина Алина Максимовна",Gender::Woman,1999,2017,666126,5.0);

	Student* newgroup[4] = { &group[0],&group[1],&group[2], newStudent };

	for (int j(0); j < countSession; j++)
	{
		for (int i(0); i < Student::counterStudent; i++)
		{
			Session session(*newgroup[i]);
			session.initialize();
			session.getResultSession();
			session.SetStudentScore();
		}
	}

	newgroup[1]->deserialize();
	return;
}