#include "DataManager.h"
#include <stdlib.h>


int main()
{
	setlocale(LC_ALL, "Russian");

	DataManager<int> manager;

	int a[60] = { 0 };

	manager.push(a, 60);

	int x = manager.peek();

	for (int i = 1; i < 4; i++)
	{
		manager.push(i);
	}

	manager.pop();
	manager.pop();

	DataManager<char> char_manager; 

	char_manager.push('h');
	char_manager.push('e');
	char_manager.push('l');
	char_manager.push('l');
	char_manager.push('o');
	char ch = char_manager.popUpper(); 

	DataManager<double> double_manager;

	for (int i = 1; i < 10; i++)
	{
		double_manager.push(sin(i));
	}

	std::cout << "\nint container " << std::endl;;
	manager.print();

	std::cout << "\nchar container " << std::endl;
	char_manager.print();

	std::cout << "\ndouble container " << std::endl;
	double_manager.print();


	system("pause");
	return 0;
}