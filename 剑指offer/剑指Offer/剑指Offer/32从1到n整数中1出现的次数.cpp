#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;
int PowerBaseTen(int n)//10��n�η�
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
	if (strN == NULL || *strN<'0' || *strN>'9' || *strN == '\0')//�����ݹ������
		return 0;
	int first = *strN - '0'; //���λ������ֵ
	unsigned int length = static_cast<unsigned int>(strlen(strN));//�ַ����ĳ���
	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 0)
		return 1;

	int numFirstDigit = 0;//���λ1���ֵĴ���
	if (first > 1)//���λ����1ʱ��1���ֵĴ���
		numFirstDigit = PowerBaseTen(length - 1);
	else if (first == 1)//���λ����1ʱ��1���ֵĴ���
		numFirstDigit = atoi(strN + 1) + 1;

	int numOtherDigit = 0;//����λ1���ֵĴ���
	numOtherDigit = first*(length - 1)*PowerBaseTen(length - 2);//ע��first��λ��

	int numRecursive = NumberOfOne(strN + 1);//�ݹ����ȥ�����λ

	return numFirstDigit + numOtherDigit + numRecursive;
}

int NumberOf1Between1AndN_Solution(int n)
{
	if (n <= 0)
		return 0;
	char strN[50];
	sprintf(strN, "%d", n);//����ת��Ϊ�ַ���������д���

	return NumberOfOne(strN);
}

