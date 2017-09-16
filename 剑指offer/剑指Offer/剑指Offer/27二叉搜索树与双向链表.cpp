#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;

/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。

*/

void ConvertTree(TreeNode* pRoot, TreeNode** pLastNodeInList) {
	if (!pRoot)
		return;
	ConvertTree(pRoot->left, pLastNodeInList);

	pRoot->left = *pLastNodeInList;//第一次赋值为空，因为头指针
	if (*pLastNodeInList != NULL) // 不为空值的时候，就为当前指针的前一个指针
		(*pLastNodeInList)->right = pRoot;
	*pLastNodeInList = pRoot;//pLastNodeInList一直保存的为前一个指针

	ConvertTree(pRoot->right, pLastNodeInList);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* pLastNodeInList = NULL;//第一次赋值为空，因为头指针
	ConvertTree(pRootOfTree, &pLastNodeInList);

	TreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList != NULL && pHeadOfList->left != NULL)//把尾指针转换为头指针
		pHeadOfList = pHeadOfList->left;
	return pHeadOfList;


}
