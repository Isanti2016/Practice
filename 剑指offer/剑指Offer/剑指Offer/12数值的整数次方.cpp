#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

bool equal(double num1, double num2);

bool InvaildPut = false;//全局变量处理错误

double Power(double base, int exponent) {
	InvaildPut = false;
	if (equal(base, 0.0) && exponent < 0)//判断double类型的底数为零,指数为负数的情况（0的正次方为1，负次方异常）
	{
		InvaildPut = true;//有异常。
		return 0.0;
	}
	if (exponent == 0)
		return 1.0;
	if (exponent == 1)//为高效率实现n次方做准备，递归跳出点
		return base;
	bool flag = false;
	if (exponent < 0)//指数为负数
	{
		exponent = -exponent;
		flag = true;
	}

	double result = Power(base, exponent >> 1);//指数减半
	result = result*result;
	if (exponent & 0x1)//利用位运算代替除以2和求余，提高效率
		result = result*base;


	return flag ? 1 / result : result;
}
bool equal(double num1, double num2)
{
	if ((num1 - num2) < 0.0000001 && (num1 - num2) > -0.0000001)//两个double类型的差在一个区域内，则相等
		return true;
	else
		return false;
}