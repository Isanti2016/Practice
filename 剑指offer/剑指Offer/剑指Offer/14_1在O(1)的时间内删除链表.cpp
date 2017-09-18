#include <iostream>
#include <vector>
#include <string>
#include "Common_head.h"

using namespace std;

//��������ĺ���
void CreateListTail(ListNode ** L, const int a[], int a_length)//��������β�巨
{
	ListNode *p, *r;

	//	*L = (ListNode*)malloc(sizeof(ListNode));//Ϊ������������ͷ���
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

bool GetNode(const ListNode* L, int i, ListNode** Node)// ListNode** Node���붨��ָ��ڵ��ָ�룬���ܷ��ؽ��
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
�����������ͷ����һ�����ָ�룬��O(1)��ʱ����ɾ���ýڵ�
*/

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (pListHead == NULL || pToBeDeleted == NULL)
	{
		return;
	}

	if (pToBeDeleted->next != NULL)//ɾ������ڵ��У��м�Ľڵ�
	{
		ListNode *p;
		p = pToBeDeleted->next;
		pToBeDeleted->val = p->val;
		pToBeDeleted->next = p->next;

		delete p;
		p = NULL;//ɾ��ָ���Ҫ�ͷ�
	}
	else if (*pListHead == pToBeDeleted)//����һ����㣬ɾ��ͷ���
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;

		*pListHead = NULL;//ͷ���ָ��գ�Ϊ������
	}
	else   //����ڵ���ɾ��β�ڵ�
	{
		ListNode *pNode = *pListHead;

		while (pNode->next != pToBeDeleted)//Ѱ��Ҫɾ���ڵ��ǰһ���ڵ�
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

	ListNode *L = (ListNode*)malloc(sizeof(ListNode));//Ϊ������������ͷ���
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



