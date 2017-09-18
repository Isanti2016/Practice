#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;

/*
������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,��\С�����Կ����κ�������0,����A����1,JΪ11,QΪ12,KΪ13
*/

bool IsContinuous(vector<int> numbers) {
	int length = numbers.size();
	if (length != 5)//���ǲ��������ƣ����ǲ���������ġ�
		return false;
	sort(numbers.begin(), numbers.end());//stl��algorithm
										 //qsort(&numbers,length,sizeof(numbers[0]),Comp);//������stdlib.h�еĺ���
	int num_zero = 0;
	int count_abs = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		//if(num_zero==length-1)//Ϊ��ֹԽ�磬�������4��0������
		//return true;
		if (numbers[i] == 0)
			num_zero++;
		else {
			int absent = numbers[i + 1] - numbers[i];
			if (absent == 0)//�����ظ�������һ���Ƿ�������˳��
				return false;
			if (absent > 1)
				count_abs += (absent - 1);
		}
	}
	return (num_zero >= count_abs) ? true : false;
}