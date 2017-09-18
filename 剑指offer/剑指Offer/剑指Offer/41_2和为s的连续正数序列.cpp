#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
/*
����һ������s����ӡ���к�Ϊs�������������У����ٰ�����������

*/
vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> result;
	result.clear();
	if (sum < 3)
		return result;
	int mid = (1 + sum) >> 1;
	int low = 1, high = 2;
	int count = low + high;

	while (low < mid&&low < high)//��Ϊ������Ҫ����������low<high
	{
		if (count<sum)
		{
			++high;
			count += high;//���ƶ�ָ�룬��ӣ��䶯�����
		}
		else if (count>sum)
		{
			count -= low;//�ȼ������ƶ�ָ�룬�䶯�����
			++low;
		}
		else
		{
			vector<int> num_de;
			for (int i = low; i <= high; ++i)
				num_de.push_back(i);
			result.push_back(num_de);
			++high;
			count += high;//ÿһ���䶯��count����Ӧ�ü�ʱ����
		}
	}
	return result;
}