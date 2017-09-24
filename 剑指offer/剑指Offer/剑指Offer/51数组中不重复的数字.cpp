#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;

/*
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�
����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡�
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
	for (int i = 0; i < length; ++i)//��Ŀ��������
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
