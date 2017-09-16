#include <iostream>
#include <vector>
#include "Common_head.h"

/*
ʹ�õݹ飬ÿ������һ����㣬���кϲ�
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
		result->val = pHead1->val;//Ϊʲô������������㣬�����ܸ�val�أ�������
		pHead1 = pHead1->next;
	}
	else
	{
		//result=pHead2;
		result->val = pHead2->val;
		pHead2 = pHead2->next;
	}
	result->next = Merge(pHead1, pHead2);//���õݹ�ʵ�ֺϲ�����
	return result;
}
/*
ʹ�ù鲢��˼�룬���кϲ����������ɽ�㡣
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
	return pNode->next;//Ҫ������һ��
}