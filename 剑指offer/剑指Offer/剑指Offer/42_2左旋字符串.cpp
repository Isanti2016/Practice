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
	if (length < n)//������Ҫ��
		return result;
	Reverse(result, 0, n - 1);//��תǰ��nλ
	Reverse(result, n, length - 1);//��ת�����
	Reverse(result, 0, length - 1);//�����巴ת�����ɴﵽ
	return result;
}
