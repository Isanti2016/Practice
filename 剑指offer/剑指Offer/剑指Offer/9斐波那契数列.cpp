#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*斐波那契数列第n项的值
0 1 1 2 3 5 8 13 21 .....
*/

int Fibonacci(unsigned n) {
	int a[2] = { 0,1 };
	if (n < 2)
		return a[n];
	int temp_1 = 0;
	int temp_2 = 1;
	int sum = 0;
	for (int i = 2; i <= n; i++)//利用循环思想实习斐波那契数列，时间复杂度为O(n)
	{
		sum = temp_1 + temp_2;
		temp_1 = temp_2;
		temp_2 = sum;
	}
	return sum;
}
