#pragma once
#include <iostream>
#include <math.h>

using namespace std;
/*
折半查找：
时间复杂度：O(n)
*/
int Binary_Search(int *a, int length, int key) {
	int index = -1;
	int low = 0, high = length, mid;
	while (low<=high)		//用等于是因为两者相邻的下一次指向同一个位置
	{
		mid = (low + high) >> 1;
		if (a[mid]<key) {
			low = mid+1;	//+1是为了移动low，防止陷入死循环
		}
		else if (a[mid]>key)
		{
			high = mid-1;
		}
		else {
			index=mid;
			break;
		}
	}
	return index;
}
/*
插值查找：	改进折半查找
时间复杂度：O(logn),最好记录集分配较为均匀
*/
int Insert_Search(int* a, int length,int key) {
	int index = -1;
	int low = 0, high = length, mid;
	while (low<=high)
	{
		mid = low + (high - low)*(key - a[low]) / (a[high] - a[low]);//插值查找
		if (mid<0||mid>length)//防止索引过界
			break;
		else if (a[mid] < key)
			low = mid + 1;
		else if (a[mid]>key)
			high = mid - 1;
		else {
			index = mid;
			break;
		}
	}
	return index;
}
/*
斐波那契查找：
时间复杂度：  O(logn) 平均性能优于折半查找
注意：		  因为仅用简单的加减运算，所有时间上会更好
*/
int Fibonacci(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n-1)+Fibonacci(n-2);
}
int Fibonacci_Search(int* a,int length,int key) {
	int index = -1;
	int low = 0, high = length, mid;
	int k = 0;
	while (length > Fibonacci(k))
		++k;
	for (int i = length + 1; i < Fibonacci(k) - 1; ++i)//把数组补充到Fibonacci(k)的大小
		a[i] = a[length];
	 while (low<=high)
	 {
		 mid = low + Fibonacci(k-1) - 1;	//用斐波那契代替中值
		 if (a[mid] < key) {
			 low = mid + 1;
			 k = k - 2;						//k一直在减小，左边的k-2
		 }
		 else if (a[mid]>key) {
			 high = mid - 1;				
			 k = k - 1;						//右边的k-1,因为Fibonacci(k)=Fibonacci(k-1)+Fibonacci(k-2)
		 }
		 else {
			 if (mid > length)
				 break;
			 else {
				 index = mid;
				 break;
			 }
		 }
	 }
	 return index;
}
/*
哈希查找：
时间赋值度:O(n)
注意：性能包括散列表是否均匀，解决冲突的方法，装填因子
*/
int Hash_length=13;
void InitHash(int a[],int length) {
	for (int i = 0; i < length;++i)
	{
		a[i] = -1;
	}
}
int Hash(const int& key) {
	return key%Hash_length;
}
void InsertHash(int a[], const int& key) {//存储和查找都要用addr，所以两者差不多。
	int addr = Hash(key);
	while (a[addr] != -1) {
		addr = Hash(addr + 1);
	}
	a[addr] = key;
}
bool SearchHash(int a[],const int& key,int& addr) {
	addr = Hash(key);
	while (a[addr] != key) {
		addr = Hash(addr + 1);
		if (addr == -1||addr==Hash(key)) {
			return false;
		}
	}
	return true;
}
typedef struct BitNode {
	int val;
	BitNode* left;
	BitNode* right;
}BitNode,*BitTree;
bool SearchBST(BitTree pRoot,int key,BitTree pPre,BitTree& p) {
	bool result=false;
	if (pRoot == NULL)
	{
		p = pPre;			//返回未搜索到的节点的前一个，是为了插入准备
		return result;
	}
	if (pRoot->val < key)
		result=SearchBST(pRoot->right, key, pRoot, p);
	else if (pRoot->val > key)
		result=SearchBST(pRoot->left, key, pRoot, p);
	else {
		result = true;
		p = pRoot;
	}
	return result;
}
bool InsertBST(BitTree pRoot, int key) {
	BitTree pPre = NULL, p = NULL;

	if (!SearchBST(pRoot, key, pPre, p))
	{
		BitTree temp = new BitNode;
		temp->val = key;
		temp->left = temp->right = NULL;
		if (p == NULL)//当为空树的时候
			p = temp;
		else if (p->val<key)
			p->right = temp;
		else 
			p->left = temp;
		return true;
	}
	else
		return false;
}
bool DeleteBST(BitTree pRoot) {
	bool result = false;
	if (pRoot->left == NULL) {

	}
	if (pRoot->right == NULL) {

	}
	return false;
}
bool DeleteBST(BitTree pRoot, int key) {
	bool result = false;
	if (pRoot == NULL)
		result=false;
	else {
		if (pRoot->val < key)
			result=DeleteBST(pRoot->right, key);
		else if (pRoot->val > key)
			result=DeleteBST(pRoot->left, key);
		else
			result=DeleteBST(pRoot);
	}
	return result;

}