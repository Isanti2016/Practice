#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;



int Add(int num1, int num2)
{
	int sum = 0, carray = 0;
	do
	{
		sum = num1^num2;//�����ӣ�����������λ
		carray = (num1&num2) << 1;//λ������,������1λ���γɽ�λ

		num1 = sum;
		num2 = carray;
	} while (carray != 0);//һֱ����ֱ��û�н�λΪֹ
	return sum;
}