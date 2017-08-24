#include <iostream>
#include "Effective.h"
using namespace std;


int main_10() {
	int b = 5;
	int* a = 0;//行为不可预测
	int* c = &b;//正常               
	cout << *c << endl;


	char* s1;
	char s2[10] = "cde";
	s1 = "cde";
//	s1++;
	strcpy_s(s2, "abc");
	cout << s1 << " " << s2 << endl;


	return 0;
}