#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;
/*
��������������2��3��5��������ϰ���ϰ�1��Ϊ��һ������
���1500������
*/
int Min_Number(int num1, int num2, int num3)//�ҳ���������С����
{
	int min_num = (num1 < num2) ? num1 : num2;
	min_num = (min_num < num3) ? min_num : num3;
	return min_num;
}

int GetUglyNumber_Solution(int index) {
	if (index <= 0)
		return 0;
	int* UglyNumber = new int[index];//��̬����һ��index��������
	UglyNumber[0] = 1;//��1������һ������
	int *Number2 = UglyNumber;//����ָ�뷽����з���
	int *Number3 = UglyNumber;
	int *Number5 = UglyNumber;
	int count = 1;

	while (count < index)
	{
		int min_num = Min_Number(*Number2 * 2, *Number3 * 3, *Number5 * 5);
		UglyNumber[count] = min_num;

		while (UglyNumber[count] >= *Number2 * 2)//�����������е������гɱ�����
			Number2++;                      //ָ���¼һֱά��һ��λ��
		while (UglyNumber[count] >= *Number3 * 3)
			Number3++;
		while (UglyNumber[count] >= *Number5 * 5)
			Number5++;
		count++;
	}
	return UglyNumber[index - 1];
}
