#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
/*
输入一个正数s，打印所有和为s的连续正数序列（至少包含两个数）

*/
vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> result;
	result.clear();
	if (sum < 3)
		return result;
	int mid = (1 + sum) >> 1;
	int low = 1, high = 2;
	int count = low + high;

	while (low < mid&&low < high)//因为最少需要两个数，而low<high
	{
		if (count<sum)
		{
			++high;
			count += high;//先移动指针，后加，变动的求和
		}
		else if (count>sum)
		{
			count -= low;//先减，后移动指针，变动的求和
			++low;
		}
		else
		{
			vector<int> num_de;
			for (int i = low; i <= high; ++i)
				num_de.push_back(i);
			result.push_back(num_de);
			++high;
			count += high;//每一处变动，count都有应该及时跟进
		}
	}
	return result;
}