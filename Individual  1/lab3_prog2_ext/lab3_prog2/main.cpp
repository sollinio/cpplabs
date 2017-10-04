#include "student.h"
#include "session.h"
#include "lecturer.h"

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	Person* persons[4];

	persons[0] = new Student();
	persons[1] = new Student();
	persons[2] = new Lecturer();
	persons[3] = new Lecturer();

	Student* student1 = dynamic_cast<Student*>(persons[0]);
	Student* student2 = dynamic_cast<Student*>(persons[1]);
	Lecturer* lecturer1 = dynamic_cast<Lecturer*>(persons[2]);
	Lecturer* lecturer2 = dynamic_cast<Lecturer*>(persons[3]);

	//first stud
	student1->setpfio("Финолин Алексей Иванович");
	student1->setbirthyear(1999);
	student1->setnumbersrb(666123);
	student1->setgender(Gender::Man);
	student1->setincomeyear(2017);
	student1->setscore(4.2);
	//second stud
	student2->setpfio("Хмельник Виктория Аркадиевна");
	student2->setbirthyear(1998);
	student2->setnumbersrb(666124);
	student2->setgender(Gender::Woman);
	student2->setincomeyear(2017);
	student2->setscore(4.9);
	//first lect
	lecturer1->setpfio("Онечь Михаил Иванович");
	lecturer1->setbirthyear(1979);
	lecturer1->setexperience(10);
	lecturer1->setposition("Старший преподаватель");
	lecturer1->setdtworkyear(1999);
	lecturer1->setgender(Gender::Man);
	lecturer1->setsciencegegree(ScienceDegree::Candidate);
	lecturer1->setsciencerank(ScienceRank::Docent);
	//second lect
	lecturer2->setpfio("Паника Юрий Вадимович");
	lecturer2->setbirthyear(1966);
	lecturer2->setexperience(7);
	lecturer2->setdtworkyear(1991);
	lecturer2->setposition("Преподаватель");
	lecturer2->setgender(Gender::Man);
	lecturer2->setsciencegegree(ScienceDegree::NoneScienceDegree);
	lecturer2->setsciencerank(ScienceRank::Professors);


	for (int i = 0; i < 4; i++)
	{
		Student* st =  dynamic_cast<Student*>(persons[i]);
		if (st)
		{
			std::cout << st->getpfio() << " Пол:" << (st->getgender() ? "M" : "Ж") << " Год:" << st->getbirthyear() << " № зач.:" << st->getstringnumber_srb()
				<< " " << st->getscore() << " Стипендия:" << st->calculate() << endl;
		}
		else
		{
			Lecturer* lect = dynamic_cast<Lecturer*>(persons[i]);
			std::cout  << lect->getpfio() << " Пол:" << (lect->getgender() ? "M" : "Ж") << " Год:" << lect->getbirthyear() << " Опыт:" << lect->getexperience() 
				<< " Научная степень:" << (lect->getsciencegegree() ? (lect->getsciencegegree() == 1 ? "Доктор" : "Кандидат") : "Нет" ) 
				<< " Научный ранг:" << (lect->getsciencerank() ? (lect->getsciencerank() == 1 ? "Доцент" : "Профессор") : "Нет") << " Оклад:" << lect->calculate() << endl;
		}
	}

	return;
}