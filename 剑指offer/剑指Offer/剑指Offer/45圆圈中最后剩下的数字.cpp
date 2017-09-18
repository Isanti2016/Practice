#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
从0，1，2，3....n-1排成一个圆圈，从数字0开始每次从这个圆圈中删除第m个数子，求圆圈中剩下的最后一个数字。
*/

int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; ++i)//当i=1的时候最后剩下的一定是0
	{
		last = (last + m) % i;
	}
	return last;//要是从1开始排成一个圆，直接return last+1即可
}