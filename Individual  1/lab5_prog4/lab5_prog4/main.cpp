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
	books.push_back(new Book("Подросток", "Достоевский Ф. М.", 2004));
	books.push_back(new Book("Война и мир", "Толстой Л. Н.", 2010));
	books.push_back(new Book("Обрыв", "Гончаров И. А.", 2010));
	books.push_back(new Book("Анна Каренина", "Толстой Л. Н.", 1999));
	books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011));
	books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009));
	books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001));
	books.push_back(new Book("Фауст", "Гёте И. В.", 2010));
	books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));

	std::vector<int> booksYears;

	std::cout << "\nСписок книг: \n\n";

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

	std::cout << "\nКоличество книг выпущенных после " << predYear << " : " << i << "\n\n";



	for (auto i = books.begin(); i != books.end(); ++i )
	{
		delete (*i);
	}

	system("pause");
	return 0;
}