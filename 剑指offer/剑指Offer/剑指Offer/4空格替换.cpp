#include <iostream>
#include <vector>
using namespace std;

void replaceSpace(char *str, int length) //length是最大空间限制
{
	int oldlength;
	int spacelength = 0;
	for (oldlength = 0; str[oldlength] != '\0'; oldlength++)
	{
		if (str[oldlength] == ' ')
		{
			spacelength++;
		}
	}
	int newlength = oldlength + spacelength * 2;
	if (newlength > length)
		return;
	str[newlength] = '\0';
	int poin1 = oldlength - 1;
	int poin2 = newlength - 1;
	for (; poin1 >= 0; poin1--)//此仅一个条件即可决定
	{
		if (str[poin1] == ' ')
		{
			str[poin2--] = '0';
			str[poin2--] = '2';
			str[poin2--] = '%';

		}
		else
		{
			str[poin2--] = str[poin1];

		}
	}
}