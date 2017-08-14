#pragma once
#include <vector>

using namespace std;
void printArray(int arr[], int size);

int partition(int a[], int low, int high) {
	int pivot = a[low];
	while (low < high) {
		while (low < high && a[high] >= pivot) 
			high--;
		a[low] = a[high];
		while (low < high && a[low] <= pivot)
			low++;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}
void Qsort(int a[], int low, int high) {
	int pivot;
	if (low < high) {
		pivot = partition(a, low, high);
		Qsort(a, low, pivot - 1);
		Qsort(a, pivot + 1, high);
		cout << "pivot+1" << endl;
	}
	cout << "out while" << endl;
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}