#include <iostream>
#include <vector>
#include "Common_head.h"

using namespace std;


vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> result;
	if (head == NULL)
		return result;
	printListFromTailToHead(head, result);
	return result;
}
void printListFromTailToHead(ListNode* head, vector<int>& result) {
	if (head == NULL)
		return;

	printListFromTailToHead(head->next, result);//寻找到尾部，在压入栈
	result.push_back(head->val);
}