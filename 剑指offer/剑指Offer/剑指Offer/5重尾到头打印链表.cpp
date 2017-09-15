#include <iostream>
#include <vector>
#include "Common_head.h"

using namespace std;

void printListFromTailToHead(ListNode* head, vector<int>& result) {
	if (head == NULL)
		return;

	printListFromTailToHead(head->next, result);//Ѱ�ҵ�β������ѹ��ջ
	result.push_back(head->val);
}
vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> result;
	if (head == NULL)
		return result;
	printListFromTailToHead(head, result);
	return result;
}
