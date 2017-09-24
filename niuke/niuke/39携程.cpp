#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
去除重复的字符串
输入：
hello world
输出：
helo wrd
*/
string Deletestr(string str) {
	string result;

	int* a = new int[256];
	for (int i = 0; i < 256; ++i)
	{
		a[i] = 0;
	}
	for (int i = 0; i < str.size(); ++i)
	{
		a[str[i]]++;
		if (str == " ")
		{
			result += str[i];
		}
		else
		{
			if (a[str[i]] == 1)
			{
				result += str[i];
			}
			else
				continue;
		}

	}
	return result;
}

int main_39()
{
	string str;
	getline(cin, str);
	string result = Deletestr(str);
	cout << result << endl;
	return 0;
}


