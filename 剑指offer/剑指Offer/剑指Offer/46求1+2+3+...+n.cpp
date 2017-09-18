#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;

int Sum_Solution(int n) {
	int result = n;
	result && (result += Sum_Solution(n - 1));//result=0时，会自动短路不执行后面的，可返回result即为1+2+....+n
	return result;
}