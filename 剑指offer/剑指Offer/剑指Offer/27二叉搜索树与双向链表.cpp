#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;

/*
����һ�ö��������������ö���������ת����һ�������˫������

*/

void ConvertTree(TreeNode* pRoot, TreeNode** pLastNodeInList) {
	if (!pRoot)
		return;
	ConvertTree(pRoot->left, pLastNodeInList);

	pRoot->left = *pLastNodeInList;//��һ�θ�ֵΪ�գ���Ϊͷָ��
	if (*pLastNodeInList != NULL) // ��Ϊ��ֵ��ʱ�򣬾�Ϊ��ǰָ���ǰһ��ָ��
		(*pLastNodeInList)->right = pRoot;
	*pLastNodeInList = pRoot;//pLastNodeInListһֱ�����Ϊǰһ��ָ��

	ConvertTree(pRoot->right, pLastNodeInList);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* pLastNodeInList = NULL;//��һ�θ�ֵΪ�գ���Ϊͷָ��
	ConvertTree(pRootOfTree, &pLastNodeInList);

	TreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList != NULL && pHeadOfList->left != NULL)//��βָ��ת��Ϊͷָ��
		pHeadOfList = pHeadOfList->left;
	return pHeadOfList;


}
