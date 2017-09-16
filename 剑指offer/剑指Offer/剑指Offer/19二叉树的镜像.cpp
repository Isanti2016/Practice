#include <iostream>
#include <vector>
#include "Common_head.h"
/*
操作给定的二叉树，将其变换为源二叉树的镜像。
*/

void Mirror(TreeNode *pRoot) {
	if (pRoot == NULL)
		return;

	TreeNode *temp = pRoot->left;//不用判断pRoot->left是否为空，因为if(pRoot==NULL)中已判断
	pRoot->left = pRoot->right;
	pRoot->right = temp;

	Mirror(pRoot->left);//不用判断pRoot->left是否为空，因为if(pRoot==NULL)中已判断
	Mirror(pRoot->right);
}
