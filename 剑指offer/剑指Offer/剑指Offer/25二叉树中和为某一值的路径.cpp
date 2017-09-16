#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
主要是，判断出是叶子结点同时和又满足要求
*/
void PathResult(TreeNode* root, int expectNumber, vector<vector<int> >& result, vector<int> path)
{
	if (root == NULL)
		return;
	int sum = 0;
	path.push_back(root->val);//先压入vector中

	if (root->left == NULL&&root->right == NULL)//两者都为空，确定为叶子节点
	{
		for (auto it = path.begin(); it != path.end(); it++)
		{
			sum += (*it);
		}
		if (sum == expectNumber)
		{
			result.push_back(path);
		}
		// path.pop_back();//不用pop_back()因为递归是path会返回。
		return;
	}
	PathResult(root->left, expectNumber, result, path);
	PathResult(root->right, expectNumber, result, path);

	path.pop_back();//完成后把pah清空
}

vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector<int> path;
	vector<vector<int> > result;
	result.clear();
	if (root == NULL)
		return result;
	PathResult(root, expectNumber, result, path);

	return result;

}
