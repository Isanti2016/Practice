#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

/*
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,�����������е�����Ե�����P��
����P��1000000007ȡģ�Ľ������� �����P%1000000007
*/

int Count_Pairs(vector<int>& data, int copy[], int low, int high)
{
	if (low == high)
		return 0;
	int mid = (low + high) >> 1;//ȡ���м����
	int leftcount = Count_Pairs(data, copy, low, mid);
	int rightcount = Count_Pairs(data, copy, mid + 1, high);
	int i, j;
	int k = high;
	int count = 0;
	for (i = mid, j = high; i >= low&&j > mid; k--)
	{
		if (data[i] > data[j])
		{
			copy[k] = data[i--];
			count += (j - mid);//ǰ��ıȺ���Ĵ�����Ը���Ϊ�����ʣ������ĸ���
			if (count >= 1000000007)//������ݹ���������࣬��ֹ����������С��
				count %= 1000000007;
		}
		else
			copy[k] = data[j--];
	}
	while (i >= low)//����������鲻һ�������������ֱ�ӿ������ݵ�data��
		copy[k--] = data[i--];
	while (j > mid)
		copy[k--] = data[j--];
	for (int i = low; i <= high; ++i)//Ҫ��data��copyͬ������Ȼ��һ�ε�����ʱ��Ͳ���������һ��copy���Ѿ�����õĽ����������ѭ��
		data[i] = copy[i];
	return (leftcount + rightcount + count) % 1000000007;
}

int InversePairs(vector<int> data) {
	int sum = 0;
	int length = data.size();
	if (length == 0)
		return sum;
	int* copy = new int[length - 1];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];
	sum = Count_Pairs(data, copy, 0, length - 1);
	delete copy;
	return sum;
}
