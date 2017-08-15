#pragma once
#include <iostream>
using namespace std;
/*
�������򣺸Ľ���ð������
ʱ����˳������� O(N^2)
ʱ�����: ƽ��O(NlogN)
�ռ���˳�������O(N)
�ռ���ã�ƽ��O(logN)
�ȶ��ԣ�  ���ȶ�
*/
int Partition(int a[], int low, int high) {
	int key = a[low];
	while (low < high) {
		while (low < high&&a[high] >= key)
			--high;
		a[low] = a[high];
		while (low < high&&a[low] <= key)
			++low;
		a[high] = a[low];
	}
	a[low] = key;
	return low;
}
void QSort(int a[], int low, int high) {
	int key;
	if (low < high)
	{
		key = Partition(a, low, high);
		QSort(a, low, key - 1);
		QSort(a, key + 1, high);
	}
}
/*
�鲢����
ʱ�临�Ӷȣ��ܵĶ���O(nlogn)
�ռ临�Ӷȣ��ܵĶ���O(n+logn)
�ȶ��ԣ�    ���������Ƚϣ��ȶ��㷨
*/
void Merge(int a[],int low,int mid,int high) {
	int* temp = new int[high + 1];//����Ҫ��high+1,��Ϊ�Ǳ��õ�length-1,��kÿ�ζ��ڼӣ�Ҫ��֤�ռ����
	for (int i = low; i <= high; ++i)
		temp[i] = a[i];
	int i = low, j = mid+1, k = low;
	while (i<=mid&&j<=high)
	{
		if (temp[i] <= temp[j])
			a[k] = temp[i++];
		else
			a[k] = temp[j++];
		++k;
	}
	while (i <= mid)
		a[k++] = temp[i++];
	while (j <= high)
		a[k++] = temp[j++];
	delete[] temp;
}
void MSort(int a[], int low, int high) {
	if (low == high)
		return;
	else
	{
		int mid = (low + high) >> 1;//���ܴ�0����1��ʼ�������������м�ֵ����midƫ��С��һ��
		MSort(a, low, mid);
		MSort(a, mid + 1,high);
		Merge(a, low, mid, high);
	}
}
/*
������           �Ľ���ѡ������
������ʱ�临�Ӷȣ� O(n)
�ؽ���ʱ�临�Ӷȣ� O(nlogn)
ʱ�临�Ӷȣ�      �ܵ���O(nlogn)
�ռ临�Ӷȣ�      O(1),����temp;
�ȶ��ԣ�          ���ȶ�
*/
void HeadAdjust(int a[],int s,int length) {
	int temp;
	temp = a[s];
	for (int i = 2 * s + 1; i <= length;i=2*i+1)
	{
		if (i < length && a[i] < a[i + 1])
			++i;
		if (a[i] <= temp)
			break;
		a[s] = a[i];
		s = i;
	}
	a[s] = temp;
}
void HeapSort(int a[],int length) {
	for (int i = (length - 1) / 2; i >= 0;--i)
	{
		HeadAdjust(a, i, length);
	}
	for (int i = length; i > 0;--i)
	{
		swap(a[0], a[i]);
		HeadAdjust(a,0,i-1);
	}
}
/*
��������
ʱ����	���� O(n^2)
ʱ�����:	˳��O(n)
ʱ�临�Ӷȣ�ƽ��ΪO(n^2)
�ռ临�Ӷȣ�O(1)
*/
void Insert_Sort(int a[], int length) {
	for (int i=1;i<=length;++i)
	{
		if (a[i]<a[i-1])
		{
			int j,temp = a[i];
			for (j=i-1;j>=0&&a[j]>temp;--j)
			{
				a[j + 1] = a[j];//���д���temp�Ķ�Ҫ����ƶ�һλ
			}
			a[j + 1] = temp;
		}
	}
}
/*
ϣ������	�Ľ��Ĳ�������
ʱ�临�Ӷȣ�O(n^(3/2))��ѧ�Ƶ�����
�ռ临�Ӷȣ�O(1);
�ȶ���    ����Ϊ��Ծ�����ȶ�
ע�⣺      increment=increment/3+1�Ϻã����һ������increment=1
*/
void ShellSort(int a[],int length){
	int increment = length;
	do
	{
		increment = increment / 3 + 1;
		for (int i = increment; i <= length;++i)//�����Ĳ�������
		{
			if (a[i]<a[i-increment])
			{
				int j, temp = a[i];
				for (j = i - increment; j >= 0 && a[j] > temp;j-=increment)
				{
					a[j + increment] = a[j];
				}
				a[j + increment] = temp;
			}
		}
	} while (increment>1);//��do...while���ʵ�ֽϷ��㣬��Ϊincrement=1ʱ����ѭ��һ�Σ�������for��while�������Ϊincrement>=1��������ѭ��
}
/*
ѡ������
�Ƚϴ�����	O(n^2)
����������	���˳��0�Σ��������n-1��
ʱ�临�Ӷȣ�O(n^2)
�ռ临�Ӷȣ�O(1)����MIN
*/
void SelectSort(int a[], int length) {
	int MIN;
	for (int i = 0; i < length;++i)//i���ӵ�length
	{
		MIN = i;
		for (int j = i + 1; j <= length;++j)
		{
			if (a[j]<a[MIN])
			{
				MIN = j;
			}
		}
		if (i!=MIN)
		{
			swap(a[i], a[MIN]);//MIN��ʾ�±꣬���㽻�����ݣ����������ݻ��޸����ݡ�
		}
	}
}
/*
�Ż����ð������BubbleSort2:
ʱ�临�Ӷȣ����˳��O(n),�������O(n^2)��ƽ��O(n^2)
*/
void BubbleSort(int a[], int length) {
	for (int i = 0; i <length;++i)//���ڿ��ƴ���
	{
		for (int j = length; j > 0;--j)//���ڿ�������֮��Ԫ�صĽ���������С��Ԫ��ð�ݵ�����
		{
			if (a[j]<a[j-1])
			{
				swap(a[j],a[j-1]);
			}
		}
	}
}
void BubbleSort2(int a[], int length) {
	bool flag = true;
	for (int i = 0; i < length && flag; ++i)
	{
		flag = false;//�����˳�����鲻�������ݣ��򲻻���ѭ��
		for (int j = length; j > 0;--j)
		{
			if (a[j]<a[j-1])
			{
				swap(a[j],a[j-1]);
				flag = true;
			}
		}
	}
}

