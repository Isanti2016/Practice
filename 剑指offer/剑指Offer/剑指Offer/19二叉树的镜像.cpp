#include <iostream>
#include <vector>
#include "Common_head.h"
/*
���������Ķ�����������任ΪԴ�������ľ���
*/

void Mirror(TreeNode *pRoot) {
	if (pRoot == NULL)
		return;

	TreeNode *temp = pRoot->left;//�����ж�pRoot->left�Ƿ�Ϊ�գ���Ϊif(pRoot==NULL)�����ж�
	pRoot->left = pRoot->right;
	pRoot->right = temp;

	Mirror(pRoot->left);//�����ж�pRoot->left�Ƿ�Ϊ�գ���Ϊif(pRoot==NULL)�����ж�
	Mirror(pRoot->right);
}
