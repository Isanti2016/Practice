#include <iostream>
#include <time.h>
#include "Searching.h"

using namespace std;

int main_6() {
	clock_t start, finish;
	double total;
	int a[] = { 0,1,16,24,35,47,59,62,73,88,99 };
	int length = sizeof(a) / sizeof(a[0]);
	cout << "original Array:" << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
	int index = -1;

	start = clock();
	for (int i = 0; i < length; ++i)
	{
		//index = Binary_Search(a, length - 1, a[i]);
		//index = Insert_Search(a, length - 1, a[i]);
		index = Fibonacci_Search(a,length-1,a[i]);
		cout << "index:" << index << endl;
	}

	//index = Binary_Search(a, length - 1, -100);
	//index = Insert_Search(a, length - 1, -100);
	index = Fibonacci_Search(a,length-1,-100);
	cout << "index:" << index << endl;

	finish = clock();
	total = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Search Total Time:" << total << "s" << endl << endl;

	system("pause");
	return 0;
}