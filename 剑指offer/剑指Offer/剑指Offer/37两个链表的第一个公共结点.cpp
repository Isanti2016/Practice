#include <iostream>
#include <vector>
#include "Common_head.h"

using namespace std;
unsigned int GetListLength(ListNode* pHead)
{
	ListNode* temp = pHead;
	unsigned count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	unsigned int length1 = GetListLength(pHead1);
	unsigned int length2 = GetListLength(pHead2);
	int lengthDif = length1 - length2;
	ListNode *temp1 = pHead1, *temp2 = pHead2;
	if (lengthDif < 0)//��֤temp1ָ�������ϳ�
	{
		lengthDif = -lengthDif;
		temp1 = pHead2;
		temp2 = pHead1;
	}
	while (lengthDif > 0)//������������lengthDif��
	{
		temp1 = temp1->next;
		--lengthDif;
	}
	while (temp1 != NULL&&temp1 != temp2)//��������һ���ߣ���ͬ������ѭ��
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return temp1;
}
