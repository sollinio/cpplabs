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
	student1->setpfio("������� ������� ��������");
	student1->setbirthyear(1999);
	student1->setnumbersrb(666123);
	student1->setgender(Gender::Man);
	student1->setincomeyear(2017);
	student1->setscore(4.2);
	//second stud
	student2->setpfio("�������� �������� ����������");
	student2->setbirthyear(1998);
	student2->setnumbersrb(666124);
	student2->setgender(Gender::Woman);
	student2->setincomeyear(2017);
	student2->setscore(4.9);
	//first lect
	lecturer1->setpfio("����� ������ ��������");
	lecturer1->setbirthyear(1979);
	lecturer1->setexperience(10);
	lecturer1->setposition("������� �������������");
	lecturer1->setdtworkyear(1999);
	lecturer1->setgender(Gender::Man);
	lecturer1->setsciencegegree(ScienceDegree::Candidate);
	lecturer1->setsciencerank(ScienceRank::Docent);
	//second lect
	lecturer2->setpfio("������ ���� ���������");
	lecturer2->setbirthyear(1966);
	lecturer2->setexperience(7);
	lecturer2->setdtworkyear(1991);
	lecturer2->setposition("�������������");
	lecturer2->setgender(Gender::Man);
	lecturer2->setsciencegegree(ScienceDegree::NoneScienceDegree);
	lecturer2->setsciencerank(ScienceRank::Professors);


	for (int i = 0; i < 4; i++)
	{
		Student* st =  dynamic_cast<Student*>(persons[i]);
		if (st)
		{
			std::cout << st->getpfio() << " ���:" << (st->getgender() ? "M" : "�") << " ���:" << st->getbirthyear() << " � ���.:" << st->getstringnumber_srb()
				<< " " << st->getscore() << " ���������:" << st->calculate() << endl;
		}
		else
		{
			Lecturer* lect = dynamic_cast<Lecturer*>(persons[i]);
			std::cout  << lect->getpfio() << " ���:" << (lect->getgender() ? "M" : "�") << " ���:" << lect->getbirthyear() << " ����:" << lect->getexperience() 
				<< " ������� �������:" << (lect->getsciencegegree() ? (lect->getsciencegegree() == 1 ? "������" : "��������") : "���" ) 
				<< " ������� ����:" << (lect->getsciencerank() ? (lect->getsciencerank() == 1 ? "������" : "���������") : "���") << " �����:" << lect->calculate() << endl;
		}
	}

	return;
}