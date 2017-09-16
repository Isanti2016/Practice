#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
分三步，复制，给random赋值，拆分
拆分的时候原链表要先走一步
*/

void CloneList(RandomListNode* pHead) {
	RandomListNode* pNode = pHead;
	while (pNode != NULL) {
		RandomListNode* ptemp = new RandomListNode(pNode->label);
		ptemp->next = pNode->next;
		ptemp->random = NULL;

		pNode->next = ptemp;
		pNode = ptemp->next;
	}
}
void ConnectRandom(RandomListNode* pHead) {
	RandomListNode* pNode = pHead;
	while (pNode != NULL) {
		RandomListNode* pClone = pNode->next;
		if (pNode->random != NULL) {
			pClone->random = pNode->random->next;
		}
		pNode = pClone->next;
	}
}
RandomListNode* ReconnectList(RandomListNode* pHead) {
	RandomListNode* pNode = pHead;
	RandomListNode* pCloneHead = NULL, *pCloneNode = NULL;
	if (pNode != NULL) {
		pCloneHead = pCloneNode = pNode->next;//一个用于返回，一个用于操作
		pNode->next = pCloneNode->next;
		pNode = pNode->next;//此处原链表先走一步
	}
	while (pNode != NULL) {
		pCloneNode->next = pNode->next;
		pCloneNode = pCloneNode->next;

		pNode->next = pCloneNode->next;//因为已经把原有链表备份链表个只能是偶数，所以不会出现一次
		pNode = pNode->next;
	}
	return pCloneHead;
}
RandomListNode* Clone(RandomListNode* pHead)
{
	CloneList(pHead);
	ConnectRandom(pHead);
	return ReconnectList(pHead);
}
