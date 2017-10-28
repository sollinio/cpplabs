#include "Book.h"
#include "BookSorter.h"
#include "BookFinder.h"

#include <algorithm>
#include <locale>
#include <vector>
#include <iostream>

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

	std::cout << "\nКниги в алфавитном порядке: \n\n";

	BookSorter book_sorter;


	std::sort(books.begin(), books.end(), book_sorter);
	std::vector<Book*>::iterator i;

	for (i = books.begin(); i != books.end(); ++i)
	{
		std::cout << (*i)->getauthor() << " \""
			<< (*i)->getname() << "\"" << std::endl;
	}

	BookFinder book_finder(2005, 2014);
	std::vector<Book*>::iterator finder = std::find_if(books.begin(), books.end(), book_finder);
	std::cout << "\nКниги в диапазоне года издания 2005 - 2014: \n\n";

	while (finder != books.end())
	{
	std::cout << (*finder)->getauthor() << " \""
		<< (*finder)->getname() << "\"" << std::endl;
		 finder = std::find_if(++finder, books.end(), book_finder);
	}


	for (auto i = books.begin(); i != books.end(); ++i)
	{
		delete (*i);
	}

	system("pause");
	return 0;
}