#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*

*/
void swap(string& str, int num1, int num2)//交换字符
{
	char temp = str[num1];
	str[num1] = str[num2];
	str[num2] = temp;
}
void Permutation(string str, set<string>&result, int begin, int end)//利用set解决元素重复，和全排后字典序输出的问题 
{
	if (begin == end - 1)
		result.insert(str);
	else
	{
		for (int i = begin; i < end; i++)
		{
			swap(str, i, begin);
			Permutation(str, result, begin + 1, end);
			swap(str, i, begin);//恢复为原来的字符串
		}
	}
}

vector<string> Permutation(string str) {
	vector<string> result;//结果
	set<string> set_result;//set解决元素重复的问题，和全排后字符串的排序，即字典序
	int length = str.size();
	if (length == 0)
	{
		return result;
	}

	Permutation(str, set_result, 0, length);

	result.assign(set_result.begin(), set_result.end());//把set转换为要求的vector
	return result;
}
