#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
bool IsBalanced(TreeNode* pRoot, int &depth)
{
	if (pRoot == NULL)
	{
		depth = 0;
		return true;
	}
	int leftdepth, rightdepth;
	bool leftis, rightis;
	leftis = IsBalanced(pRoot->left, leftdepth);
	rightis = IsBalanced(pRoot->right, rightdepth);//叶子节点
	if (leftis&&rightis) {
		int diff = leftdepth - rightdepth;
		if (diff <= 1 && diff >= -1)//必须在两个范围之间
		{
			depth = 1 + (leftdepth > rightdepth ? leftdepth : rightdepth);
			return true;
		}
		else
			return false;
	}
	return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	int depth = 0;
	return IsBalanced(pRoot, depth);
}
