#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
�����������ƣ���random��ֵ�����
��ֵ�ʱ��ԭ����Ҫ����һ��
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
		pCloneHead = pCloneNode = pNode->next;//һ�����ڷ��أ�һ�����ڲ���
		pNode->next = pCloneNode->next;
		pNode = pNode->next;//�˴�ԭ��������һ��
	}
	while (pNode != NULL) {
		pCloneNode->next = pNode->next;
		pCloneNode = pCloneNode->next;

		pNode->next = pCloneNode->next;//��Ϊ�Ѿ���ԭ�������������ֻ����ż�������Բ������һ��
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
