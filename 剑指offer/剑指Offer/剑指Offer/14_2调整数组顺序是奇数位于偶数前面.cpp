#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reOrderArray(vector<int> &array) {
	if (array.size() == 0)
	{
		return;
	}
	int begin = 0, end = array.size() - 1;
	while (begin<end)
	{
		while (begin < end && (array[begin] & 1 != 0))//向后移动，直到指向一个偶数
			begin++;
		while (begin<end&&(array[begin]&&1)==0)//向前移动，直到指向一个奇数
			end--;
		if (begin<end)
		{
			swap(array[begin],array[end]);
		}
	}
}