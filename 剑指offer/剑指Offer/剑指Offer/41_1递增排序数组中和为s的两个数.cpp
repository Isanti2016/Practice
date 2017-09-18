#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
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
		if (array[low] + array[high]<sum)//和小于sum则low向后走
			low++;
		else if (array[low] + array[high]>sum)//和大于sum则high向下走
			high--;
		else	//两者和为sum
		{
			product = array[low] * array[high];
			if (product < Min)//寻找符合要求，且乘积最小的一对。
			{
				Min = product;
				num1 = array[low];
				num2 = array[high];
				flag = true;//为了区分如果没有找到这么一对，不能用[0,0]充数
			}
			low++;//此处要变换，不然找到一对后，不会在动
		}

	}
	if (flag)
	{
		result.push_back(num1);
		result.push_back(num2);
	}
	return result;

}