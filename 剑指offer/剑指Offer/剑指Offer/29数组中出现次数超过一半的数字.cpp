#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
*/
bool CheckMoreThanHalf(vector<int> number, int length, int result)
{
	bool res = false;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (number[i] == result)
			count++;
	}
	if ((count << 1) > length)
		res = true;
	else
		res = false;
	return res;
}
//����1
int MoreThanHalfNum_Solution_1(vector<int> numbers) {//��������������ص�
	int length = numbers.size();
	if (length == 0)
		return 0;
	int result = numbers[0];
	int count = 1;
	for (int i = 1; i < length; i++)//�ӵڶ����ֿ�ʼ����
	{
		if (numbers[i] == result)
		{
			count++;
		}
		else
			count--;
		if (count == 0)//����
		{
			result = numbers[i];
			count = 1;
		}
	}
	if (!CheckMoreThanHalf(numbers, length, result))//������ڣ���result��һ���������Ҫ���ҵ���
		return 0;
	return result;
}
//������
int MoreThanHalfNum_Solution(vector<int> numbers) {//��������������ص�
	int length = numbers.size();
	if (length == 0)
		return 0;
	int result = numbers[0];
	int count = 1;
	for (int i = 1; i < length; i++)//�ӵڶ����ֿ�ʼ����
	{
		if (numbers[i] == result)
		{
			count++;
		}
		else
			count--;
		if (count == 0)//����
		{
			result = numbers[i];
			count = 1;
		}
	}
	if (!CheckMoreThanHalf(numbers, length, result))//������ڣ���result��һ���������Ҫ���ҵ���
		return 0;
	return result;
}
