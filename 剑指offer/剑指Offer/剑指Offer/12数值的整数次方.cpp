#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*/

bool equal(double num1, double num2);

bool InvaildPut = false;//ȫ�ֱ����������

double Power(double base, int exponent) {
	InvaildPut = false;
	if (equal(base, 0.0) && exponent < 0)//�ж�double���͵ĵ���Ϊ��,ָ��Ϊ�����������0�����η�Ϊ1�����η��쳣��
	{
		InvaildPut = true;//���쳣��
		return 0.0;
	}
	if (exponent == 0)
		return 1.0;
	if (exponent == 1)//Ϊ��Ч��ʵ��n�η���׼�����ݹ�������
		return base;
	bool flag = false;
	if (exponent < 0)//ָ��Ϊ����
	{
		exponent = -exponent;
		flag = true;
	}

	double result = Power(base, exponent >> 1);//ָ������
	result = result*result;
	if (exponent & 0x1)//����λ����������2�����࣬���Ч��
		result = result*base;


	return flag ? 1 / result : result;
}
bool equal(double num1, double num2)
{
	if ((num1 - num2) < 0.0000001 && (num1 - num2) > -0.0000001)//����double���͵Ĳ���һ�������ڣ������
		return true;
	else
		return false;
}