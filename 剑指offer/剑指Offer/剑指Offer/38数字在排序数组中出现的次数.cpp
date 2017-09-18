#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
/*
方法一，找到k的一个，再向后和向前进行统计
*/
int Find(vector<int> data, int k, int low, int high)
{
	while (low <= high)//注意条件
	{
		int mid = (low + high) >> 1;
		if (data[mid]<k)
			low = mid + 1;
		else if (data[mid]>k)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

int GetNumberOfK(vector<int> data, int k) {
	int length = data.size();
	if (length == 0)
		return 0;
	int index = Find(data, k, 0, length - 1);
	if (index == -1)//代表没有查到
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



/*
使用二分查找，查找第一个k和最后一个k的位置
输入：
1 2 3 3 3 3 4 5
3
输出
4
*/

int GetLastIndex_OfK(const vector<int>& vec, int k) {
	int start = 0;
	int end = vec.size() - 1;
	int mid;
	while (start <= end)
	{
		mid = (start + end) >> 1;
		if (vec[mid] > k)
		{
			end = mid - 1;
		}
		else if (vec[mid] < k)
		{
			start = mid + 1;
		}
		else
		{
			if ((mid + 1) <= vec.size() - 1 && vec[mid + 1] == k)//寻找最后一个k的值
				start = mid + 1;
			else
				return mid;
		}
	}
	return -1;
}
int GetFirstIndex_OfK(const vector<int>& vec, int k) {
	int start = 0;
	int end = vec.size() - 1;
	int mid;
	while (start <= end)
	{
		mid = (start + end) >> 1;
		if (vec[mid] > k)
		{
			end = mid - 1;
		}
		else if (vec[mid] < k)
		{
			start = mid + 1;
		}
		else
		{
			if ((mid - 1) >=0 && vec[mid -1] == k)//寻找最后一个k的值
				end = mid - 1;
			else
				return mid;
		}
	}
	return -1;
}
int main() {
	string str;
	int k;
	getline(cin, str);
	cin >> k;
	stringstream ss(str);

	int temp;
	vector<int> vec;
	while (ss >> temp)
	{
		vec.push_back(temp);
	}
	//for (int i = 0; i < vec.size(); ++i)
	//{
	//	int result = GetIndex_OfK(vec, vec[i]);
	//	cout << result << endl;
	//}
	int indexfirst = GetFirstIndex_OfK(vec, k);
	int indexlast = GetLastIndex_OfK(vec, k);
	if (indexfirst != -1 && indexlast != -1)
	{
		cout << indexlast - indexfirst + 1 << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}
