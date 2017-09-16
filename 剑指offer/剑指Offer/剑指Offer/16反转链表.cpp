#include <iostream>
#include <vector>
#include "Common_head.h"



ListNode* ReverseList(ListNode* pHead) {
	if (pHead == NULL)
		return NULL;
	ListNode* pNode = pHead;
	ListNode* pNext = pNode->next;
	ListNode* r;
	pNode->next = NULL;
	while (pNext != NULL) {
		r = pNext->next;
		pNext->next = pNode;
		pNode = pNext;
		pNext = r;
	}
	return pNode;
}