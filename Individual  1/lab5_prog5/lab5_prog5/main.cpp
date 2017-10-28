#include <stdlib.h>

#include "Cache.h"
#include <iostream>

int main()
{
	Cache<int> cache;
	cache.put(1); // ��� ������ ��������
	cache.put(2);
	cache.put(3);
	cache += 5; // ��� ���� ������ ��������

	Cache<std::string> voc;
	voc.put("OK");
	std::cout << voc.contains("Only") << std::endl; // 1

	std::cout << cache.contains(5) << std::endl; // 1

	system("pause");

	return 0;
}

