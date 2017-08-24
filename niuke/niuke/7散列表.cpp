//#include <iostream>
//#include "Searching.h"//同一个头文件，多个.cpp包含出现重复定义的问题，所以屏蔽
//
//using namespace std;
//
//int main(){
//	int a[13];
//	int b[11]= { 0,1,16,24,35,47,59,62,73,88,99 };
//	InitHash(a,13);
//	for (int i = 0; i < 11;++i)
//	{
//		InsertHash(a,b[i]);
//	}
//	cout << "number in the Hash a[]" << endl;
//	for (int i = 0; i < 13;++i)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	int Index_Hash;
//	for (int i = 0; i < 11; ++i)
//	{
//		if (SearchHash(a, b[i], Index_Hash))
//		{
//			cout << "Index_Hash:"<<b[i]<<"::"<< Index_Hash << endl;
//		}
//		else {
//			cout << "No This Number:" << endl;
//		}
//	}
//	if (SearchHash(a, 101, Index_Hash))
//	{
//		cout << "Index_Hash:" << Index_Hash << endl;
//	}
//	else {
//		cout << "No This Number:" << endl;
//	}
//	return 0;
//}