#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

int XOR(vector<int> data, int length)//数组data异或的结果
{
	int result = 0;
	for (int i = 0; i < length; ++i)
	{
		result ^= data[i];
	}
	return result;
}
int IsBitOne(int num)//数字num右起第一个为1的二进制为的位置
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
	if (length < 2)//小于2都是有错的数组data
		return;
	int result_xor = XOR(data, length);
	int index_Bit = IsBitOne(result_xor);
	for (int i = 0; i < length; ++i)
	{
		if (IsBitOne(data[i]) == index_Bit)//第index_Bit位为1的数组
			*num1 ^= data[i];
		else							//第index_Bit位为0的数组
			*num2 ^= data[i];
	}
}
