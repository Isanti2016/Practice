#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*쳲��������е�n���ֵ
0 1 1 2 3 5 8 13 21 .....
*/

int Fibonacci(unsigned n) {
	int a[2] = { 0,1 };
	if (n < 2)
		return a[n];
	int temp_1 = 0;
	int temp_2 = 1;
	int sum = 0;
	for (int i = 2; i <= n; i++)//����ѭ��˼��ʵϰ쳲��������У�ʱ�临�Ӷ�ΪO(n)
	{
		sum = temp_1 + temp_2;
		temp_1 = temp_2;
		temp_2 = sum;
	}
	return sum;
}
