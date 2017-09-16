#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
二叉树的层序遍历
*/
vector<int> PrintFromTopToBottom(TreeNode* root) {

	queue<TreeNode*> Tree_deque;
	Tree_deque.push(root);

	vector<int> result;
	result.clear();

	while (!Tree_deque.empty())
	{
		TreeNode* temp = Tree_deque.front();//访问栈顶元素
		Tree_deque.pop();//弹出队顶中的元素
		if (!temp)//为空,注意此处细节，因为把所有叶子节点的子结点（空的）也压入进去了
			continue;
		result.push_back(temp->val);
		Tree_deque.push(temp->left);
		Tree_deque.push(temp->right);
	}

	return result;
}