#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <iterator>
#include <algorithm>

template <typename Type>
class DataManager
{
	Type* typearray;
	const int maxarrlen = 64;
	int arrlen = 0;
	int powdump = 0;

	void savedumpFile()
	{
		++powdump;
		std::ofstream fout("dump.dat", std::ios::app);
		for (int i = 0; i < maxarrlen; i++)
		{
			fout << typearray[i] << std::endl;
			typearray[i] = 0;
		}

		fout.close();

	}

	void loaddumpFile()
	{
		--powdump;
		std::ifstream fin("dump.dat");
		for (int i = 0; i < maxarrlen * powdump; i++)
		{
			if (i < maxarrlen * (powdump - 1))
				continue;
			fin >> typearray[i];
		}

		recoverydumpFile();

		fin.close();
	}

	void recoverydumpFile()
	{
		std::ofstream fout("dump1.dat");
		std::ifstream fin("dump.dat");

		for (int i = 0; i < maxarrlen * powdump; i++)
		{
			Type tmp;
			fin >> tmp;
			fout << tmp << std::endl;
		}

		fout.close();
		fout.open("dump.dat");

		fin.close();
		fin.open("dump1.dat");

		for (int i = 0; i < maxarrlen * powdump; i++)
		{
			Type tmp;
			fin >> tmp;
			fout << tmp << std::endl;
		}

		fin.close();
		fout.close();

		remove("dump1.dat");

		
	}


public:

	Type* begin()
	{
		return typearray;
	}

	Type* end()
	{
		return typearray + arrlen - (maxarrlen * powdump);
	}

	void push(Type elem)
	{
		if (arrlen - (maxarrlen * powdump) == maxarrlen)
			savedumpFile();
		typearray[arrlen - (maxarrlen * powdump)] = elem;
		++arrlen;
	}

	void push(Type elem[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			if (arrlen - (maxarrlen * powdump) == maxarrlen)
				savedumpFile();
			typearray[arrlen - (maxarrlen * powdump)] = elem[i];
			++arrlen;
		}
	}

	Type peek()
	{
		try
		{
			if (arrlen - (maxarrlen * powdump) < 2)
				throw arrlen;

			Type tmp = typearray[arrlen - (maxarrlen * powdump) - 2];


			return tmp;
		}
		catch(int ex)
		{
			std::cout << "Невозможно считать предпоследний элемент, их всего" << ex << std::endl;
			return 0;
		}
	}

	Type pop()
	{
		try
		{
			if (arrlen - (maxarrlen * powdump) == 0)
				if (powdump == 0)
					throw 0;
				else
					loaddumpFile();
					
			int mid = arrlen - (maxarrlen * powdump) / 2 - (arrlen - (maxarrlen * powdump) % 2 == 0 ? 1 : 0);
			Type ret = typearray[mid];			
			typearray[arrlen - (maxarrlen * powdump) - 2] = typearray[arrlen - (maxarrlen * powdump) - 1];

			arrlen--;
			return ret;
		}
		catch (int)
		{
			std::cout << "Нет элементов в стеке" << std::endl;
			return 0;
		}
	}

	void print()
	{
		std::copy(
			begin(),
			end(),
			std::ostream_iterator<Type>(std::cout, " "));
	}

	DataManager() 
	{
		typearray = new Type[maxarrlen];

		for (int i = 0; i < maxarrlen; i++)
		{
			typearray[i] = 0;
		}

	};
	~DataManager() 
	{ 
	};
};

template <>
class DataManager<char>
{
	char* typearray;
	const int punkarraylen = 4;
	const int maxarrlen = 64;
	int arrlen = 0;
	char punkarray[4] = { ':',',',';','-' };

public:

	char* begin()
	{
		return typearray;
	}

	char* end()
	{
		return typearray + arrlen;
	}

	void push(char inner_char)
	{
		try
		{
			if (arrlen == maxarrlen)
				throw 0;

			for (int i = 0; i < punkarraylen; i++)
			{
				if (inner_char == punkarray[i])
					inner_char = '_';
			}

			typearray[arrlen++] = inner_char;

		}
		catch (int)
		{
			std::cout << "Стек полон";
		}
	}

	char popUpper()
	{
		try
		{
			if (arrlen == 0)
				throw 0;
			char tmp = std::toupper(typearray[arrlen - 1]);
			typearray[arrlen--] = '\0';
			return tmp;
		}
		catch (int)
		{
			std::cout << "Стек пуст";
			return 0;
		}
	}

	char popLower()
	{
		try
		{
			if (arrlen == 0)
				throw 0;
			char tmp = std::tolower(typearray[arrlen - 1]);
			typearray[arrlen--] = '\0';
			return tmp;
		}
		catch (int)
		{
			std::cout << "Стек пуст";
			return 0;
		}
	}

	void print()
	{
		std::copy(
			begin(),
			end(),
			std::ostream_iterator<char>(std::cout, " "));
	}

	DataManager()
	{
		typearray = new char[maxarrlen];

		for (int i = 0; i < maxarrlen; i++)
		{
			typearray[i] = 0;
		}

	};
	~DataManager()
	{

	};
};