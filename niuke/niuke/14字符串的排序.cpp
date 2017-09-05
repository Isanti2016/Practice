/*
字母的全排序
输入：
aab    //有字母重复的问题
abc
输出：
aab aba aab aba baa baa
abc acb bac bca cba cab
*/
#include<iostream>

using namespace std;

void Sort_Str(char* str, char* begin) {
	if (*begin == '\0')
	{
		cout << str << " ";
	}
	else {
		for (char* temp = begin; *temp != '\0'; ++temp)
		{
			swap(*temp, *begin);
			Sort_Str(str, begin + 1);
			swap(*temp, *begin);
		}
	}
}

int main_14_p() {
	char str[100];
	cin >> str;
	Sort_Str(str, str);
	return 0;
}

/*
vector<int> vec数组的全排列
8皇后92种摆放的问题，首先全排列，从全排列中找出不符合条件的，在用总的全排列数-不符合条件的
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//void Sort_num(vector<int>& vec, int num,vector<vector<int>>& result) {
//	if (num==vec.size()-1)
//	{
//		result.push_back(vec);
//	}
//	for (int i = num; i < vec.size(); ++i) {
//		swap(vec[i],vec[num]);
//		Sort_num(vec, num + 1,result);
//		swap(vec[i], vec[num]);
//	}
//}
//int main_14() {
//	//vector<int> vec = { 0,1,2,3,4,5,6,7 };//8皇后
//	vector<int> vec = { 0,1,2,3};//4皇后
//	vector<vector<int>> result;
//
//	Sort_num(vec,0,result);
//
//	for (int i = 0; i < result.size(); ++i) {
//		for (int j = 0; j < result[i].size(); ++j)
//		{
//			cout << result[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "总共全排列个数：" << result.size() << endl;
//
//	bool flag = true;
//	int count = 0;
//	for (int i = 0; i < result.size(); ++i) {
//		for (int j = 0; flag &&j < result[i].size()-1; ++j)
//		{
//			for (int k = j + 1;  k < result[i].size();++k)
//			{
//				if ((k-j==result[i][k]-result[i][j])||( k - j == result[i][j] - result[i][k]))
//				{
//					flag = false;  //不符合条件的
//				}
//			}
//		}
//		if (!flag)
//		{
//			count++;
//			flag = true;
//		}
//	}
//	cout <<"总共皇后可以摆放的方法有："<< result.size()-count << endl;
//	return 0;
//}


/*
字母的组合，要求字符不重复如aaaa则不可，abc可以，没用set去重
输入：
abc
输出：
a
b
c
ab
ac
bc
abc
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

int main_14_z()
{
	char s[100];
	cin >> s;
	int count = 0;
	Combination(s,count);
	cout << "组合的个数：" << count << endl;
	system("pause");
	return 0;
}