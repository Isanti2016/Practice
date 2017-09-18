#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
/*
输入：
I am a student.
输出：
student. a am I
*/
void Reverse(string& str, int low, int high)
{
	while (low < high)//注意反转的条件，不应该拿中值比较。
	{
		swap(str[low++], str[high--]);//调用系统的swap函数进行反转
	}
}

string ReverseSentence(string str) {
	string result = str;
	int length = str.size();
	if (length == 0)
		return result;
	Reverse(result, 0, length - 1);//反转整个句子
	int i = 0, j = 1;//j=1是为了防止越界
	while (j < length)
	{
		if (j == length - 1)//包含仅有一个单词或者最后一个单词后面没有空格的情况，进行反转
			Reverse(result, i, j);
		if (result[j] == ' ')//根据空格反转每个单词
		{
			Reverse(result, i, j - 1);
			j++;
			i = j;
		}
		j++;
	}
	return result;
}
