#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>


using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> result;
	result.clear();
	int length = input.size();
	if (k <= 0 || length == 0 || length < k)
		return result;
	multiset<int, greater<int> > res_set;//此题中最小的k个数可以是重复的,所以用multiset。greater在<functional>中，决定最大的在头部，方便删除，插入
	for (int i = 0; i < length; i++)
	{
		if (i < k)
		{
			res_set.insert(input[i]);
		}
		else
		{
			if (input[i] < (*res_set.begin()))
			{
				res_set.erase(res_set.begin());//不能擦除具体数字，只能擦除迭代器指向的数字
				res_set.insert(input[i]);
			}
		}
	}
	result.assign(res_set.begin(), res_set.end());//给结果赋值
	return result;
}
