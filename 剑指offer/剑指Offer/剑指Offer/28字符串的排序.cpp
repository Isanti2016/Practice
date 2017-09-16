#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*

*/
void swap(string& str, int num1, int num2)//�����ַ�
{
	char temp = str[num1];
	str[num1] = str[num2];
	str[num2] = temp;
}
void Permutation(string str, set<string>&result, int begin, int end)//����set���Ԫ���ظ�����ȫ�ź��ֵ������������ 
{
	if (begin == end - 1)
		result.insert(str);
	else
	{
		for (int i = begin; i < end; i++)
		{
			swap(str, i, begin);
			Permutation(str, result, begin + 1, end);
			swap(str, i, begin);//�ָ�Ϊԭ�����ַ���
		}
	}
}

vector<string> Permutation(string str) {
	vector<string> result;//���
	set<string> set_result;//set���Ԫ���ظ������⣬��ȫ�ź��ַ��������򣬼��ֵ���
	int length = str.size();
	if (length == 0)
	{
		return result;
	}

	Permutation(str, set_result, 0, length);

	result.assign(set_result.begin(), set_result.end());//��setת��ΪҪ���vector
	return result;
}
