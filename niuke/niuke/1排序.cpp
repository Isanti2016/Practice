#include <iostream>
#include <time.h>
#include "Sortting.h"

using namespace std;

int main() {
	clock_t start, finish;
	double totaltime;

	int a[] = {50,10,90,30,70,40,80,60,20};
	int length = sizeof(a) / sizeof(a[0]);
	cout << "original array:" << endl;
	for (int i = 0; i < length;++i){
		cout << a[i] << " ";
	}
	cout << endl << endl;;

	start = clock();
	//QSort(a,0,length-1);
	//MSort(a, 0, length - 1);
	HeapSort(a, length - 1);
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "qsort totaltime:" << totaltime << "s" << endl << endl;;


	cout << "Sorting Array:" << endl;
	for (int i = 0; i < length;++i){
		cout << a[i] << " ";
	}
	cout << endl;
}