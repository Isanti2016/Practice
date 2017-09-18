#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
/*
����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
*/
vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int> result;
	result.clear();
	int length = array.size();
	if (length < 2)
		return result;
	int Min = 0x7fffffff;
	int	product = 0, num1 = 0, num2 = 0;
	int low = 0, high = length - 1;
	bool flag = false;
	while (low < high)
	{
		if (array[low] + array[high]<sum)//��С��sum��low�����
			low++;
		else if (array[low] + array[high]>sum)//�ʹ���sum��high������
			high--;
		else	//���ߺ�Ϊsum
		{
			product = array[low] * array[high];
			if (product < Min)//Ѱ�ҷ���Ҫ���ҳ˻���С��һ�ԡ�
			{
				Min = product;
				num1 = array[low];
				num2 = array[high];
				flag = true;//Ϊ���������û���ҵ���ôһ�ԣ�������[0,0]����
			}
			low++;//�˴�Ҫ�任����Ȼ�ҵ�һ�Ժ󣬲����ڶ�
		}

	}
	if (flag)
	{
		result.push_back(num1);
		result.push_back(num2);
	}
	return result;

}