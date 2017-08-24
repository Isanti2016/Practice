#pragma once
#include <iostream>
#include <math.h>

using namespace std;
/*
�۰���ң�
ʱ�临�Ӷȣ�O(n)
*/
int Binary_Search(int *a, int length, int key) {
	int index = -1;
	int low = 0, high = length, mid;
	while (low<=high)		//�õ�������Ϊ�������ڵ���һ��ָ��ͬһ��λ��
	{
		mid = (low + high) >> 1;
		if (a[mid]<key) {
			low = mid+1;	//+1��Ϊ���ƶ�low����ֹ������ѭ��
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
��ֵ���ң�	�Ľ��۰����
ʱ�临�Ӷȣ�O(logn),��ü�¼�������Ϊ����
*/
int Insert_Search(int* a, int length,int key) {
	int index = -1;
	int low = 0, high = length, mid;
	while (low<=high)
	{
		mid = low + (high - low)*(key - a[low]) / (a[high] - a[low]);//��ֵ����
		if (mid<0||mid>length)//��ֹ��������
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
쳲��������ң�
ʱ�临�Ӷȣ�  O(logn) ƽ�����������۰����
ע�⣺		  ��Ϊ���ü򵥵ļӼ����㣬����ʱ���ϻ����
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
	for (int i = length + 1; i < Fibonacci(k) - 1; ++i)//�����鲹�䵽Fibonacci(k)�Ĵ�С
		a[i] = a[length];
	 while (low<=high)
	 {
		 mid = low + Fibonacci(k-1) - 1;	//��쳲�����������ֵ
		 if (a[mid] < key) {
			 low = mid + 1;
			 k = k - 2;						//kһֱ�ڼ�С����ߵ�k-2
		 }
		 else if (a[mid]>key) {
			 high = mid - 1;				
			 k = k - 1;						//�ұߵ�k-1,��ΪFibonacci(k)=Fibonacci(k-1)+Fibonacci(k-2)
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
��ϣ���ң�
ʱ�丳ֵ��:O(n)
ע�⣺���ܰ���ɢ�б��Ƿ���ȣ������ͻ�ķ�����װ������
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
void InsertHash(int a[], const int& key) {//�洢�Ͳ��Ҷ�Ҫ��addr���������߲�ࡣ
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
		p = pPre;			//����δ�������Ľڵ��ǰһ������Ϊ�˲���׼��
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
		if (p == NULL)//��Ϊ������ʱ��
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