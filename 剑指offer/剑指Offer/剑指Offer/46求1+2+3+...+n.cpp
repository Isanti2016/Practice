#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;

int Sum_Solution(int n) {
	int result = n;
	result && (result += Sum_Solution(n - 1));//result=0ʱ�����Զ���·��ִ�к���ģ��ɷ���result��Ϊ1+2+....+n
	return result;
}