#include <iostream>
#include <vector>
using namespace std;

void replaceSpace(char *str, int length) //length�����ռ�����
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
	for (; poin1 >= 0; poin1--)//�˽�һ���������ɾ���
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