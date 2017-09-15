#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*跳台阶
一次跳一阶，或者一次跳二阶,n个台阶有多少中调法
*/

int jumpFloor(unsigned number) {
	int a[3] = { 0,1,2 };
	if (number < 3)
		return a[number];
	int sum = 0;
	int temp1 = 1;
	int temp2 = 2;
	for (int i = 3; i <= number; i++)
	{
		sum = temp1 + temp2;
		temp1 = temp2;
		temp2 = sum;
	}
	return sum;
}
/*
变态跳台阶：一次跳1阶，2阶，也可以n阶，问n个台阶有多少中跳法？
*/
int jumpFloorII(unsigned number) {
	int a[2] = { 0,1 };
	if (number < 2)
		return a[number];
	int sum = 1;
	for (int i = 2; i <= number; i++)//循环实现2^(n-1)次方
	{
		sum = sum * 2;
	}
	return sum;
}

/*
矩形覆盖：用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

*/

int rectCover(unsigned number) {
	int a[3] = { 0,1,2 };
	if (number < 3)
		return a[number];
	int temp1 = 1;
	int temp2 = 2;
	int sum = 0;
	for (int i = 3; i <= number; i++)
	{
		sum = temp1 + temp2;
		temp1 = temp2;
		temp2 = sum;
	}
	return sum;
}