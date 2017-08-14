#include <iostream>
#include "Qsort.h"

using namespace std;

int main()
{
	int a[] = { 50,10,90,30,70,40,80,60,20 };
	int length=sizeof(a)/sizeof(a[0]);
	Qsort(a,0,length-1);
	printf("Sorted array: \n");
	printArray(a,length);
}
