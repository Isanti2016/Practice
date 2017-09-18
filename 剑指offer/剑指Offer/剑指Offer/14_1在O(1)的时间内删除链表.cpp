#include <iostream>
#include <vector>
#include <string>
#include "Common_head.h"

using namespace std;

//用于链表的函数
void CreateListTail(ListNode ** L, const int a[], int a_length)//创建链表，尾插法
{
	ListNode *p, *r;

	//	*L = (ListNode*)malloc(sizeof(ListNode));//为整个链表生成头结点
	r = *L;
	for (int i = 0; i < a_length; i++)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->val = a[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
void PrintNode(ListNode* L)
{
	ListNode* p;
	p = L->next;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetNode(const ListNode* L, int i, ListNode** Node)// ListNode** Node必须定义指向节点的指针，才能返回结点
{
	ListNode *p;
	int j = 1;
	p = L->next;
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)
	{
		return false;
	}
	*Node = p;
	return true;
}
/*
给定单链表的头结点和一个结点指针，在O(1)的时间内删除该节点
*/

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (pListHead == NULL || pToBeDeleted == NULL)
	{
		return;
	}

	if (pToBeDeleted->next != NULL)//删除多个节点中，中间的节点
	{
		ListNode *p;
		p = pToBeDeleted->next;
		pToBeDeleted->val = p->val;
		pToBeDeleted->next = p->next;

		delete p;
		p = NULL;//删除指针后要释放
	}
	else if (*pListHead == pToBeDeleted)//仅有一个结点，删除头结点
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;

		*pListHead = NULL;//头结点指向空，为空链表
	}
	else   //多个节点中删除尾节点
	{
		ListNode *pNode = *pListHead;

		while (pNode->next != pToBeDeleted)//寻找要删除节点的前一个节点
		{
			pNode = pNode->next;
		}
		pNode->val = NULL;

		delete pToBeDeleted;
		pToBeDeleted = NULL;

	}
}
int main_14()
{
	int a[8] = { 1,5,6,8,9,45,2,63 };

	ListNode *L = (ListNode*)malloc(sizeof(ListNode));//为整个链表生成头结点
	L->val = 0;
	L->val = NULL;
	int a_length = sizeof(a) / sizeof(a[0]);
	CreateListTail(&L, a, a_length);
	PrintNode(L);

	ListNode *pToBeDeleted;
	if (GetNode(L, 3, &pToBeDeleted))
	{
		DeleteNode(&L, pToBeDeleted);
		PrintNode(L);
	}
	else
	{
		cout << "no the ListNode in the L" << endl;
	}

	return 0;
}



