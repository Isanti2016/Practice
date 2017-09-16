#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
�������Ĳ������
*/
vector<int> PrintFromTopToBottom(TreeNode* root) {

	queue<TreeNode*> Tree_deque;
	Tree_deque.push(root);

	vector<int> result;
	result.clear();

	while (!Tree_deque.empty())
	{
		TreeNode* temp = Tree_deque.front();//����ջ��Ԫ��
		Tree_deque.pop();//�����Ӷ��е�Ԫ��
		if (!temp)//Ϊ��,ע��˴�ϸ�ڣ���Ϊ������Ҷ�ӽڵ���ӽ�㣨�յģ�Ҳѹ���ȥ��
			continue;
		result.push_back(temp->val);
		Tree_deque.push(temp->left);
		Tree_deque.push(temp->right);
	}

	return result;
}