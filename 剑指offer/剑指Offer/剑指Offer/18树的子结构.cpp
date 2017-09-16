#include <iostream>
#include <vector>
#include "Common_head.h"

bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2)//�����жϺ������Ƿ����
{
	if (pRoot2 == NULL)//������ǰ��
		return true;
	if (pRoot1 == NULL)//�����룬��Խ��,��pRoot1���������һ����pRoot2�����ʱ��pRoot1->left������⣬�����ں���
		return false;
	if (pRoot1->val == pRoot2->val)
		return IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right);
	else
		return false;
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)//���õݹ飬д����������ԭ���ǣ���һ��pRoot2�����κ�����������
												   //�͵ڶ���pRoot2Ϊ��,��pRoot2������ɣ�������ȣ������ݹ�
{
	bool result = false;
	if (pRoot2 == NULL)//���������κ�������������ǰ��
		return false;
	if (pRoot1 == NULL)//���������������ں���
		return false;

	if (pRoot1->val == pRoot2->val)
	{
		result = IsSubTree(pRoot1, pRoot2);//���뷵��һ��bool���ͽ�������ܾ����Ƿ��ٴα���pRoot1������
	}
	if (!result)//Ҫ�Ѳ������������������ֿ�����Ȼ�������ҵ��ˣ���Ҫ�����������ڲ���һ��
	{
		result = HasSubtree(pRoot1->left, pRoot2);
	}
	if (!result)
	{
		result = HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}

