#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;

void Reverse(string& str, int low, int high)
{
	while (low < high)
	{
		swap(str[low++], str[high--]);
	}
}

string LeftRotateString(string str, int n) {
	string result = str;
	int length = str.size();
	if (length < n)//不满足要求
		return result;
	Reverse(result, 0, n - 1);//反转前面n位
	Reverse(result, n, length - 1);//反转后面的
	Reverse(result, 0, length - 1);//在整体反转，即可达到
	return result;
}
