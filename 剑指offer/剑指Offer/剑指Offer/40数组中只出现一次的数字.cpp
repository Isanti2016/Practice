#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
/*
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/

int XOR(vector<int> data, int length)//����data���Ľ��
{
	int result = 0;
	for (int i = 0; i < length; ++i)
	{
		result ^= data[i];
	}
	return result;
}
int IsBitOne(int num)//����num�����һ��Ϊ1�Ķ�����Ϊ��λ��
{
	int temp = 1;
	int index = 0;
	while (!(num&temp))
	{
		temp = temp << 1;
		index++;
	}
	return index;
}

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	int length = data.size();
	if (length < 2)//С��2�����д������data
		return;
	int result_xor = XOR(data, length);
	int index_Bit = IsBitOne(result_xor);
	for (int i = 0; i < length; ++i)
	{
		if (IsBitOne(data[i]) == index_Bit)//��index_BitλΪ1������
			*num1 ^= data[i];
		else							//��index_BitλΪ0������
			*num2 ^= data[i];
	}
}
