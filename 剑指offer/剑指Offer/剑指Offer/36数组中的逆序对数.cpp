#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007
*/

int Count_Pairs(vector<int>& data, int copy[], int low, int high)
{
	if (low == high)
		return 0;
	int mid = (low + high) >> 1;//取出中间的数
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
			count += (j - mid);//前面的比后面的大，逆序对个数为后面的剩余数组的个数
			if (count >= 1000000007)//如果数据过大就先求余，防止超过整数大小。
				count %= 1000000007;
		}
		else
			copy[k] = data[j--];
	}
	while (i >= low)//如果两个数组不一样长，多出来的直接拷贝数据到data中
		copy[k--] = data[i--];
	while (j > mid)
		copy[k--] = data[j--];
	for (int i = low; i <= high; ++i)//要把data和copy同步，不然下一次迭代的时候就不能利用上一次copy中已经排序好的结果，陷入死循环
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
