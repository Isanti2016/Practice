#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;

int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL)//Ҷ�ӽڵ���Ӵ��Ϳն�����ͳһ
		return 0;
	int leftdepth = TreeDepth(pRoot->left) + 1;//����������ȣ�ʵ��������ѹջ
	int rightdepth = TreeDepth(pRoot->right) + 1;
	int result = (leftdepth > rightdepth) ? leftdepth : rightdepth;
	return result;
}