#include <iostream>
#include <vector>
#include <stack>
#include "Common_head.h"

using namespace std;

/*
递归实现
*/
//前序变量
void PreOrderTraverse(BitTree pHead)
{
	if (pHead == NULL)
		return;
	cout << pHead->val << endl;
	PreOrderTraverse(pHead->lchild);
	PreOrderTraverse(pHead->rchild);
}
//中序遍历
void InOrderTraverse(BitTree pHead)
{
	if (pHead == NULL)
		return;
	InOrderTraverse(pHead->lchild);
	cout << pHead->val << endl;
	InOrderTraverse(pHead->rchild);
}
//后序遍历
void PostOrderTraverse(BitTree pHead)
{
	if (pHead == NULL)
		return;
	PostOrderTraverse(pHead->lchild);
	PostOrderTraverse(pHead->rchild);
	cout << pHead->val << endl;
}

/*
非递归实现
原理：有重合元素的局部有序一定能导致整体有序如：2 3 4 5 6 8 10   
其中2 3 4；4 5 6；6 8 10；三个都是有序的，且重复元素为4，6，会导致整体有序。

这种思想的好处是将算法与顺序分离，定义何种顺序并不影响算法，算法只做这么一件事：
将栈顶元素取出，使以此元素为“根”结点的局部有序入栈，但若此前已通过该结点将其局部入栈，则直接出栈输出即可。
*/

//前序遍历
void preorderTraversalNew(TreeNode *root, vector<int> &path)
{
	stack<pair<TreeNode *, bool> > s;
	s.push(make_pair(root, false));
	bool visited;
	while (!s.empty())
	{
		root = s.top().first;
		visited = s.top().second;
		s.pop();
		if (root == NULL)
			continue;
		if (visited)
		{
			path.push_back(root->val);
		}
		else
		{
			s.push(make_pair(root->right, false));
			s.push(make_pair(root->left, false));
			s.push(make_pair(root, true));
		}
	}
}
//中序遍历
void inorderTraversalNew(TreeNode *root, vector<int> &path)
{
	stack< pair<TreeNode *, bool> > s;
	s.push(make_pair(root, false));
	bool visited;
	while (!s.empty())
	{
		root = s.top().first;
		visited = s.top().second;
		s.pop();
		if (root == NULL)
			continue;
		if (visited)
		{
			path.push_back(root->val);
		}
		else
		{
			s.push(make_pair(root->right, false));
			s.push(make_pair(root, true));
			s.push(make_pair(root->left, false));
		}
	}
}


//后序遍历
void postorderTraversalNew(TreeNode *root, vector<int> &path)
{
	stack< pair<TreeNode *, bool> > s;
	s.push(make_pair(root, false));
	bool visited;
	while (!s.empty())
	{
		root = s.top().first;
		visited = s.top().second;
		s.pop();
		if (root == NULL)
			continue;
		if (visited)
		{
			path.push_back(root->val);
		}
		else
		{
			s.push(make_pair(root, true));
			s.push(make_pair(root->right, false));
			s.push(make_pair(root->left, false));
		}
	}
}


