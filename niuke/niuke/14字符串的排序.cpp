/*
字母的排序
*/
//#include<iostream>
//
//using namespace std;
//
//void Sort_Str(char* str, char* begin) {
//	if (*begin=='\0')
//	{
//		cout << str << " ";
//	}
//	else {
//		for (char* temp = begin; *temp != '\0'; ++temp)
//		{
//			swap(*temp, *begin);
//			Sort_Str(str, begin + 1);
//			swap(*temp, *begin);
//		}
//	}
//}
//
//int main() {
//	char str[100];
//	cin >> str;
//	Sort_Str(str, str);
//	return 0;
//}


/*
字母的组合，要求字符不重复如aaaa则不可，abc可以
*/
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

//从头扫描字符串得到第一个字符，针对第一个字符，有两种选择
//把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符；
//如果不把这个字符放到组合中去，则需要在剩下的n-1个字符中选取m个字符 
void Combination(char* string, int number, vector<char>& result,int& count)
{
	if (number == 0)
	{
		++count;
		vector<char>::iterator iter = result.begin();
		for (; iter < result.end(); ++iter)
			cout << (*iter);
		cout << endl;
		return;
	}
	if (*string == '\0')
		return;
	result.push_back(*string);
	Combination(string + 1, number - 1, result,count);//把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符
	result.pop_back();
	Combination(string + 1, number, result,count);//不把这个字符放到组合中去，则需要在剩下的n-1个字符中选取m个字符 
}

void Combination(char* string,int& count)
{
	if (string == NULL)
		return;
	int length = strlen(string);
	vector<char> result;
	for (int i = 1; i <= length; i++)//i的值代表一个组合有多少个字符
	{
		Combination(string, i, result,count);
	}
}

int main_14()
{
	char s[100];
	cin >> s;
	int count = 0;
	Combination(s,count);
	cout << "组合的个数：" << count << endl;
	system("pause");
	return 0;
}