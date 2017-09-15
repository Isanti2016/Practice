
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int Min(vector<int> vec);

int minNumberInRotateArray(vector<int> rotateArray) {
	if (rotateArray.size() == 0)
		return -1;
	int low = 0, high = rotateArray.size() - 1;
	int mid = low;
	while (rotateArray[low] >= rotateArray[high])//判断是否为有序数组，是则返回第一个值
	{
		if (low == high - 1)//两者相差1则返回
		{
			mid = high;
			break;
		}
		mid = (low + high) / 2;
		if (rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high])//无法判断位于前面递增还是后面递增
			return Min(rotateArray);
		if (rotateArray[low] <= rotateArray[mid])//前面递增数组
			low = mid;
		if (rotateArray[mid] <= rotateArray[high])//后面递增数组
			high = mid;
	}
	return rotateArray[mid];
}
int Min(vector<int> vec)
{
	int temp = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] < temp)
			temp = vec[i];
	}
	return temp;
}