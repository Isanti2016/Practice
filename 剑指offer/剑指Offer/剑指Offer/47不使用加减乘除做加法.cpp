#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;



int Add(int num1, int num2)
{
	int sum = 0, carray = 0;
	do
	{
		sum = num1^num2;//异或相加，而不产生进位
		carray = (num1&num2) << 1;//位与运算,并左移1位，形成进位

		num1 = sum;
		num2 = carray;
	} while (carray != 0);//一直运算直到没有进位为止
	return sum;
}