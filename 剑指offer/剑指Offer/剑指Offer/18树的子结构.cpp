#include <iostream>
#include <vector>
#include "Common_head.h"

bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2)//用于判断和子树是否相等
{
	if (pRoot2 == NULL)//必须在前面
		return true;
	if (pRoot1 == NULL)//不加入，会越界,如pRoot1左子树最后一个和pRoot2根相等时，pRoot1->left会出问题，必须在后面
		return false;
	if (pRoot1->val == pRoot2->val)
		return IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right);
	else
		return false;
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)//利用递归，写两个函数的原因是，第一次pRoot2不是任何树的子树，
												   //和第二次pRoot2为空,是pRoot2遍历完成，两者相等，跳出递归
{
	bool result = false;
	if (pRoot2 == NULL)//空树不是任何树的子树，在前面
		return false;
	if (pRoot1 == NULL)//空树不含子树，在后面
		return false;

	if (pRoot1->val == pRoot2->val)
	{
		result = IsSubTree(pRoot1, pRoot2);//必须返回一个bool类型结果，才能决定是否再次遍历pRoot1的子树
	}
	if (!result)//要把查找左子树和右子树分开，不然左树中找到了，还要在右子树中在查找一遍
	{
		result = HasSubtree(pRoot1->left, pRoot2);
	}
	if (!result)
	{
		result = HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}

