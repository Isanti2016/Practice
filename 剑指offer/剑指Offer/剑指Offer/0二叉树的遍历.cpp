#include <iostream>
#include <vector>
#include <stack>
#include "Common_head.h"

using namespace std;

/*
�ݹ�ʵ��
*/
//ǰ�����
void PreOrderTraverse(BitTree pHead)
{
	if (pHead == NULL)
		return;
	cout << pHead->val << endl;
	PreOrderTraverse(pHead->lchild);
	PreOrderTraverse(pHead->rchild);
}
//�������
void InOrderTraverse(BitTree pHead)
{
	if (pHead == NULL)
		return;
	InOrderTraverse(pHead->lchild);
	cout << pHead->val << endl;
	InOrderTraverse(pHead->rchild);
}
//�������
void PostOrderTraverse(BitTree pHead)
{
	if (pHead == NULL)
		return;
	PostOrderTraverse(pHead->lchild);
	PostOrderTraverse(pHead->rchild);
	cout << pHead->val << endl;
}

/*
�ǵݹ�ʵ��
ԭ�����غ�Ԫ�صľֲ�����һ���ܵ������������磺2 3 4 5 6 8 10   
����2 3 4��4 5 6��6 8 10��������������ģ����ظ�Ԫ��Ϊ4��6���ᵼ����������

����˼��ĺô��ǽ��㷨��˳����룬�������˳�򲢲�Ӱ���㷨���㷨ֻ����ôһ���£�
��ջ��Ԫ��ȡ����ʹ�Դ�Ԫ��Ϊ���������ľֲ�������ջ��������ǰ��ͨ���ý�㽫��ֲ���ջ����ֱ�ӳ�ջ������ɡ�
*/

//ǰ�����
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
//�������
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


//�������
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


