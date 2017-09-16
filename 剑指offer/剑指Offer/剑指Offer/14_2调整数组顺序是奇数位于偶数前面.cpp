#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
调整数组顺序是奇数位于偶数前面,并且奇数和偶数的相对位置不变。
*/

void reOrderArray(vector<int> &array) {
	if (array.size() == 0)
	{
		return;
	}
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] & 1)//为奇数
		{
			int temp = array[i];
			int j = i - 1;
			while (!(array[j] & 1) && j >= 0)//利用插入排序,要注意j>=0,不然j--可能越界
			{
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = temp;
		}

	}
}
/*
调整数组顺序是奇数位于偶数前面。
*/
void reOrderArray_1(vector<int> &array) {
	if (array.size() == 0)
	{
		return;
	}
	int pbegin = 0, pend = array.size() - 1;
	while (pbegin<pend)
	{
		while (pbegin < pend && (array[pbegin] & 1 != 0))//向后移动，直到指向一个偶数
			pbegin++;
		while (pbegin<pend&&(array[pbegin]&&1)==0)//向前移动，直到指向一个奇数
			pend--;
		if (pbegin<pend)
		{
			swap(array[pbegin],array[pend]);
		}
	}
}