#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;

/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，
但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
*/

void swap(int numbers[], int num1, int num2)
{
	int temp = numbers[num1];
	numbers[num1] = numbers[num2];
	numbers[num2] = temp;
}

bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == NULL || length == 0)
		return false;
	for (int i = 0; i < length; ++i)//题目条件限制
	{
		if (numbers[i] < 0 || numbers[i] >= length)
			return 0;
	}
	bool result = false;
	int i = 0;
	while (i < length)
	{
		if (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				result = true;
				break;
			}
			swap(numbers, numbers[i], i);
		}
		else 
		{
			i++;
		}
	}
	return result;
}
