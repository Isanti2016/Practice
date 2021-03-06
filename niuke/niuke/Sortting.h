#pragma once
#include <iostream>
using namespace std;
/*
快速排序：改进的冒泡排序
时间最差：顺序或逆序 O(N^2)
时间最好: 平均O(NlogN)
空间最差：顺序或逆序O(N)
空间最好：平均O(logN)
稳定性：  不稳定
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
归并排序：
时间复杂度：总的都是O(nlogn)
空间复杂度：总的都是O(n+logn)
稳定性：    都是两两比较，稳定算法
*/
void Merge(int a[],int low,int mid,int high) {
	int* temp = new int[high + 1];//必须要用high+1,因为那边用的length-1,而k每次都在加，要保证空间充足
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
		int mid = (low + high) >> 1;//不管从0或者1开始都是这样计算中间值，且mid偏向小的一方
		MSort(a, low, mid);
		MSort(a, mid + 1,high);
		Merge(a, low, mid, high);
	}
}
/*
堆排序：           改进的选择排序
构建堆时间复杂度： O(n)
重建堆时间复杂度： O(nlogn)
时间复杂度：      总的是O(nlogn)
空间复杂度：      O(1),就是temp;
稳定性：          不稳定
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
插入排序：
时间最差：	逆序 O(n^2)
时间最好:	顺序O(n)
时间复杂度：平均为O(n^2)
空间复杂度：O(1)
*/
void Insert_Sort(int a[], int length) {
	for (int i=1;i<=length;++i)
	{
		if (a[i]<a[i-1])
		{
			int j,temp = a[i];
			for (j=i-1;j>=0&&a[j]>temp;--j)
			{
				a[j + 1] = a[j];//所有大于temp的都要向后移动一位
			}
			a[j + 1] = temp;
		}
	}
}
/*
希尔排序：	改进的插入排序
时间复杂度：O(n^(3/2))数学推导出的
空间复杂度：O(1);
稳定性    ：因为跳跃，不稳定
注意：      increment=increment/3+1较好，最后一个增量increment=1
*/
void ShellSort(int a[],int length){
	int increment = length;
	do
	{
		increment = increment / 3 + 1;
		for (int i = increment; i <= length;++i)//正常的插入排序
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
	} while (increment>1);//用do...while语句实现较方便，因为increment=1时必须循环一次，而条件for或while条件如果为increment>=1会陷入死循环
}
/*
选择排序：
比较次数：	O(n^2)
交换次数：	最好顺序0次，最差逆序n-1次
时间复杂度：O(n^2)
空间复杂度：O(1)就是MIN
*/
void SelectSort(int a[], int length) {
	int MIN;
	for (int i = 0; i < length;++i)//i不加到length
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
			swap(a[i], a[MIN]);//MIN表示下标，方便交换数据，不交换数据会修改数据。
		}
	}
}
/*
优化后的冒泡排序BubbleSort2:
时间复杂度：最好顺序O(n),最差逆序O(n^2)，平均O(n^2)
*/
void BubbleSort(int a[], int length) {
	for (int i = 0; i <length;++i)//用于控制次数
	{
		for (int j = length; j > 0;--j)//用于控制相邻之间元素的交换，把最小的元素冒泡到顶部
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
		flag = false;//如果是顺序数组不交换数据，则不会在循环
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

