#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
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
//方法1
int MoreThanHalfNum_Solution_1(vector<int> numbers) {//利用数组自身的特点
	int length = numbers.size();
	if (length == 0)
		return 0;
	int result = numbers[0];
	int count = 1;
	for (int i = 1; i < length; i++)//从第二数字开始计数
	{
		if (numbers[i] == result)
		{
			count++;
		}
		else
			count--;
		if (count == 0)//重置
		{
			result = numbers[i];
			count = 1;
		}
	}
	if (!CheckMoreThanHalf(numbers, length, result))//如果存在，则result中一定保存的是要查找的数
		return 0;
	return result;
}
//方法二
int MoreThanHalfNum_Solution(vector<int> numbers) {//利用数组自身的特点
	int length = numbers.size();
	if (length == 0)
		return 0;
	int result = numbers[0];
	int count = 1;
	for (int i = 1; i < length; i++)//从第二数字开始计数
	{
		if (numbers[i] == result)
		{
			count++;
		}
		else
			count--;
		if (count == 0)//重置
		{
			result = numbers[i];
			count = 1;
		}
	}
	if (!CheckMoreThanHalf(numbers, length, result))//如果存在，则result中一定保存的是要查找的数
		return 0;
	return result;
}
