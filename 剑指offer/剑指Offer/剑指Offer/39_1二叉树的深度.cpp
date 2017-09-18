#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;

int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL)//叶子节点的子代和空二叉树统一
		return 0;
	int leftdepth = TreeDepth(pRoot->left) + 1;//左子树的深度，实际上是在压栈
	int rightdepth = TreeDepth(pRoot->right) + 1;
	int result = (leftdepth > rightdepth) ? leftdepth : rightdepth;
	return result;
}