#include <iostream>
#include <vector>
#include "Common_head.h"


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL || k == 0)//防御性编程
		return NULL;
	ListNode *pAhead = pListHead;
	ListNode *result = pListHead;

	for (int i = 0; i < k - 1; i++)//pAhead先走k-1步
	{
		if (pAhead->next)//寻找到第一个结点，先判断，再移位
			pAhead = pAhead->next;
		else
			return NULL;
	}
	while (pAhead->next)//两者一起走，两者相差k,result即为倒数第k个节点
	{
		pAhead = pAhead->next;
		result = result->next;
	}
	return result;
}