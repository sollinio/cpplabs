#include <cstdio>
#include <cstring>
#include <clocale>

using namespace std;


char* test_strchr(char* str, int c)
{
	for (int i(0); *(str + i) != '\0'; i++)
	{
		if (*(str + i) == (char)c)
		{
			return (str + i);
		}
	}
	return NULL;
}

void main()
{
	setlocale(LC_ALL,"Russian");
	char* str = new char[255];
	char c = 0;
	printf("������� ������ s: ");
	scanf("%s",str);

	printf("������� ������ �: ");
	scanf(" %c", &c);
	
	printf("������ strchr: ");
	printf("%s\n\n", strchr(str, c));
	printf("������ test_strchr: ");
	printf("%s\n\n", test_strchr(str, c));

	return;
}