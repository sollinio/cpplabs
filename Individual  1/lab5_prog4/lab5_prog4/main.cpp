#include "Book.h"

#include <algorithm>
#include <locale>
#include <vector>
#include <iostream>
#include <functional> 
#include <iomanip>

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	std::vector<Book*> books;
	books.push_back(new Book("���������", "����������� �. �.", 2004));
	books.push_back(new Book("����� � ���", "������� �. �.", 2010));
	books.push_back(new Book("�����", "�������� �. �.", 2010));
	books.push_back(new Book("���� ��������", "������� �. �.", 1999));
	books.push_back(new Book("������������ �������", "�������� �.�.", 2011));
	books.push_back(new Book("���������� �������", "������� �.", 2009));
	books.push_back(new Book("������ �����", "������� �.", 2001));
	books.push_back(new Book("�����", "ø�� �. �.", 2010));
	books.push_back(new Book("����� ������", "������� �.", 1998));

	std::vector<int> booksYears;

	std::cout << "\n������ ����: \n\n";

	//output books and inner year in vector with name booksYears
	for (auto i = books.begin(); i != books.end(); ++i)
	{
		std::cout
			<< (*i)->getauthor()
			<< "\"" << (*i)->getname() << "\"\t"
			<<(*i)->getyearreleasebook() << std::endl;
		
		booksYears.push_back((*i)->getyearreleasebook());
	}

	int predYear = 2009;

	int i = std::count_if(
		booksYears.begin(),
		booksYears.end(),
		std::bind2nd(std::greater<int>(), predYear));

	std::cout << "\n���������� ���� ���������� ����� " << predYear << " : " << i << "\n\n";



	for (auto i = books.begin(); i != books.end(); ++i )
	{
		delete (*i);
	}

	system("pause");
	return 0;
}