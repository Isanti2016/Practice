#include <iostream>
#include <vector>
#include "Common_head.h"

/*
使用递归，每次生成一个结点，进行合并
*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	ListNode* result = (ListNode*)malloc(sizeof(ListNode));
	if (pHead1->val <= pHead2->val)
	{
		//result=pHead1;
		result->val = pHead1->val;//为什么给的是整个结点，而不能给val呢？？？？
		pHead1 = pHead1->next;
	}
	else
	{
		//result=pHead2;
		result->val = pHead2->val;
		pHead2 = pHead2->next;
	}
	result->next = Merge(pHead1, pHead2);//利用递归实现合并链表
	return result;
}
/*
使用归并的思想，进行合并，不用生成结点。
*/
ListNode* Merge_1(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* pNode = new ListNode(-1);
	ListNode* pCur = pNode;
	while (pHead1&&pHead2) {
		if (pHead1->val <= pHead2->val) {
			pCur->next = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			pCur->next = pHead2;
			pHead2 = pHead2->next;
		}
		pCur = pCur->next;
	}
	if (pHead1) {
		pCur->next = pHead1;
	}
	if (pHead2)
		pCur->next = pHead2;
	return pNode->next;//要返回下一个
}