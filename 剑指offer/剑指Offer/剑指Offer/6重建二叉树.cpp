#include <iostream>
#include <vector>
#include <string>
#include "Common_head.h"

using namespace std;

/*����ǰ��������ؽ�����������֤�������ظ�
���룺
ǰ���1��2��4��7��3��5��6��8��
�����4��7��2��1��5��3��8��6��

*/

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.empty() || vin.empty())
		return NULL;
	TreeNode *root = new TreeNode(pre[0]);
	vector<int> left_pre, left_vin, right_pre, right_vin;
	int mid = 0;
	for (auto it = vin.begin(); it != vin.end() && *it != pre[0]; it++)
		mid++;
	for (int i = 0; i < pre.size(); i++)
	{
		if (i<mid)
		{
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}
		else if (i>mid)
		{
			right_pre.push_back(pre[i]);//�˴���i,��Ϊpre[i]���ñ�vin[i]��1
			right_vin.push_back(vin[i]);
		}

	}

	root->left = reConstructBinaryTree(left_pre, left_vin);
	root->right = reConstructBinaryTree(right_pre, right_vin);
	return root;

}