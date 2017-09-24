#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {

	}
};
struct RandomListNode {//∏¥‘”¡¥±Ì
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef struct BitNode {
	int val;
	BitNode* lchild, *rchild;
}BitNode,*BitTree;

