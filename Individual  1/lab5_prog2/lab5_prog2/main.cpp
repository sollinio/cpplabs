#define _CRT_SECURE_NO_WARNINGS

#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

int main()
{
	std::map<std::string, int> dict;
	std::multimap<int, std::string> dictout;

	std::ifstream fin("source.txt");
	
	const int maxsize = 10000;

	while (!fin.eof())
	{
		const size_t MAXLEN = 1000;
		char text[MAXLEN];
		fin.getline(text, MAXLEN);
		char* substr = std::strtok(text, ".,:!;? ");
		while (substr != 0)
		{
			std::string word = substr;
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			substr = std::strtok(NULL, ".,:!;? ");

			auto result = dict.find(word);

			if (result != dict.end())
			{
				result->second++;
			}
			else
			{
				dict.insert(std::pair<std::string, int>(word, 1));
			}
		}
	}

	std::map<std::string, int>::iterator it = dict.begin();

	for (it; it != dict.end(); it++)
	{
			if (it->second >= 7 && it->first.length() > 3)
				dictout.insert(std::pair<int,std::string >(it->second, it->first));
	}
	
	std::multimap<int, std::string >::iterator it2 = dictout.end();
	
	for (it2--; it2 != dictout.begin(); it2--)
	{
		std::cout << it2->first << " " << it2->second << std::endl ;
	}

	system("pause");
	return 0;
}