#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*��̨��
һ����һ�ף�����һ��������,n��̨���ж����е���
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
��̬��̨�ף�һ����1�ף�2�ף�Ҳ����n�ף���n��̨���ж�����������
*/
int jumpFloorII(unsigned number) {
	int a[2] = { 0,1 };
	if (number < 2)
		return a[number];
	int sum = 1;
	for (int i = 2; i <= number; i++)//ѭ��ʵ��2^(n-1)�η�
	{
		sum = sum * 2;
	}
	return sum;
}

/*
���θ��ǣ���2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

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