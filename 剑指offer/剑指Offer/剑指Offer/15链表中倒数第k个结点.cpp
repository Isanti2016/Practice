#include <iostream>
#include <vector>
#include "Common_head.h"


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL || k == 0)//�����Ա��
		return NULL;
	ListNode *pAhead = pListHead;
	ListNode *result = pListHead;

	for (int i = 0; i < k - 1; i++)//pAhead����k-1��
	{
		if (pAhead->next)//Ѱ�ҵ���һ����㣬���жϣ�����λ
			pAhead = pAhead->next;
		else
			return NULL;
	}
	while (pAhead->next)//����һ���ߣ��������k,result��Ϊ������k���ڵ�
	{
		pAhead = pAhead->next;
		result = result->next;
	}
	return result;
}