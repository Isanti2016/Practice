#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/
int  NumberOf1(int n) {
	int count = 0;
	while (n)
	{
		count++;
		n = n&(n - 1);
	}
	return count;
}