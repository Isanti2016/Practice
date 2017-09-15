#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#include<iostream>

using namespace std;

void Print1ToMaxofNDigits(int n);
void Print1ToMaxofNDigits_1(int n);
void Print1ToMaxofNDigits(char* number, int length, int index);
bool Increatement(char *number);
void PrintNumber(char *number);

int main_13()
{
	Print1ToMaxofNDigits_1(3);
	return 0;
}
/*
����1���ַ���+1ģ��
*/
void Print1ToMaxofNDigits(int n)
{
	if (n <=0)
		return;

	char* number = new char[n + 1];
	memset(number,'0',n);
	number[n] = '\0';
	while (!Increatement(number))
	{
		PrintNumber(number);
	}

	delete[] number;
	number = NULL;//delete����ʱ��ֵΪNULL
}
bool Increatement(char *number)
{
	bool IsOverflow = false;
	int nTakeOver = 0;//��λ��־
	int nlenghth = strlen(number);
	for (int i=nlenghth-1;i>=0;i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nlenghth - 1)
			nSum+=1;
		if (nSum>=10)//����10��λ
		{
			if (i == 0)
				IsOverflow = true;
			else
			{
				nSum=nSum - 10;
				number[i] = nSum + '0';
				nTakeOver = 1;
			}
		}
		else
		{
			number[i] = nSum + '0';
			break;
		}
	}
	return IsOverflow;
}

/*
����2������ģ��
*/
void Print1ToMaxofNDigits_1(int n) {
	if (n < 0)
		return;
	char* numbers = new char[n + 1];
	memset(numbers, '0', n);
	numbers[n] = '\0';
	for (int i = 0; i < 10; ++i)//��ѭ���е��õݹ�
	{
		numbers[0] = i + '0';
		Print1ToMaxofNDigits(numbers, n, 0);
	}

	delete[] numbers;
}
void Print1ToMaxofNDigits(char* number, int length, int index) {
	if (index == length - 1)//��Ϊindex��0��ʼ
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxofNDigits(number, length, index + 1);
	}


}
void PrintNumber(char *number) {
	int length = strlen(number);
	bool flag = true;
	for (int i = 0; i < length; ++i)
	{
		if (flag && number[i] != '0')
			flag = false;
		if (!flag)
		{
			cout << number[i];
		}
	}
	cout << endl;
}
