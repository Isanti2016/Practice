#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
/*
{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(
*/

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.size() == 0)
		return 0;
	int tempSum = array[0];
	int maxSum = array[0];
	for (int i = 1; i < array.size(); i++) {
		tempSum = (tempSum > 0) ? tempSum + array[i] : array[i];
		maxSum = (maxSum > tempSum) ? maxSum : tempSum;
	}
	return maxSum;
}