/*
快速查找在数组中出现的次数，使用折半查找法
*/
#include <iostream>
#include <vector>
using namespace std;

int GetNumberOfK(vector<int> data, int k);
int Find(vector<int> data, int k, int low, int high);
int main_4()
{
	vector<int> data = {1,2,3,3,3,3,4,5};
	int result = GetNumberOfK(data, 3);
	cout << result << endl;
	return 0;
}
int GetNumberOfK(vector<int> data, int k) {
	int length = data.size();
	if (length == 0)
		return 0;
	int index = Find(data, k, 0, length-1);
	if (index == -1)
		return 0;
	int highcount = 0, lowcount = 0;
	for (int i = index + 1; i < length; ++i)
	{
		if (data[i] == k)
			highcount++;
	}
	for (int i = index - 1; i >= 0; --i)
	{
		if (data[i] == k)
			lowcount++;
	}
	return highcount + lowcount + 1;
}
int Find(vector<int> data, int k, int low, int high)
{
	while (low <= high)
	{
		int mid = (low + high) >> 1;
		if (data[mid]<k)
			low = mid+1;
		else if (data[mid]>k)
			high = mid-1;
		else
			return mid;
	}
	return -1;
}