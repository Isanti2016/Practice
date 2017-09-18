#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;
int PowerBaseTen(int n)//10的n次方
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}
int NumberOfOne(char* strN)
{
	if (strN == NULL || *strN<'0' || *strN>'9' || *strN == '\0')//跳出递归的条件
		return 0;
	int first = *strN - '0'; //最高位的整数值
	unsigned int length = static_cast<unsigned int>(strlen(strN));//字符串的长度
	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 0)
		return 1;

	int numFirstDigit = 0;//最高位1出现的次数
	if (first > 1)//最高位大于1时，1出现的次数
		numFirstDigit = PowerBaseTen(length - 1);
	else if (first == 1)//最高位等于1时，1出现的次数
		numFirstDigit = atoi(strN + 1) + 1;

	int numOtherDigit = 0;//其他位1出现的次数
	numOtherDigit = first*(length - 1)*PowerBaseTen(length - 2);//注意first的位置

	int numRecursive = NumberOfOne(strN + 1);//递归分析去除最高位

	return numFirstDigit + numOtherDigit + numRecursive;
}

int NumberOf1Between1AndN_Solution(int n)
{
	if (n <= 0)
		return 0;
	char strN[50];
	sprintf(strN, "%d", n);//整数转换为字符串方便进行处理

	return NumberOfOne(strN);
}

