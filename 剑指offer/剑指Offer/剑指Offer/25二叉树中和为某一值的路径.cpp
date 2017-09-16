#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
��Ҫ�ǣ��жϳ���Ҷ�ӽ��ͬʱ��������Ҫ��
*/
void PathResult(TreeNode* root, int expectNumber, vector<vector<int> >& result, vector<int> path)
{
	if (root == NULL)
		return;
	int sum = 0;
	path.push_back(root->val);//��ѹ��vector��

	if (root->left == NULL&&root->right == NULL)//���߶�Ϊ�գ�ȷ��ΪҶ�ӽڵ�
	{
		for (auto it = path.begin(); it != path.end(); it++)
		{
			sum += (*it);
		}
		if (sum == expectNumber)
		{
			result.push_back(path);
		}
		// path.pop_back();//����pop_back()��Ϊ�ݹ���path�᷵�ء�
		return;
	}
	PathResult(root->left, expectNumber, result, path);
	PathResult(root->right, expectNumber, result, path);

	path.pop_back();//��ɺ��pah���
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
