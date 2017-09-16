#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;

/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
*/
bool Verify(vector<int> sequence)
{
	int length = sequence.size();
	if (length == 0 || length == 1)//递归时为0或1，跳出递归标志
		return true;
	vector<int> left_sque;
	vector<int> right_sque;

	int root = sequence[length - 1];

	bool flag = false;

	for (int i = 0; i < length - 1; i++)
	{
		if (sequence[i] < root)//序列左半部分
		{
			if (flag)//先大于后小于不是任何二叉搜索树的后序遍历
				return false;
			left_sque.push_back(sequence[i]);

		}

		if (sequence[i] > root)//序列右半部分
		{
			right_sque.push_back(sequence[i]);
			flag = true;
		}

	}
	return Verify(left_sque) && Verify(right_sque);

}

bool VerifySquenceOfBST(vector<int> sequence) {
	int length = sequence.size();
	if (length == 0)//第一次为0，不是任何二叉搜索树的后序遍历
		return false;
	bool result = Verify(sequence);
	return result;

}
