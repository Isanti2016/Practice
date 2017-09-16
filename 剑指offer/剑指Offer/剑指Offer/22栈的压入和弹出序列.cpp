#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
输入
1,2,3,4,5
4，5,3,2,1
输出
true
*/

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	if (pushV.size() != popV.size())
		return false;
	if (pushV.empty() || popV.empty())
		return false;
	stack<int> temp;
	int j = 0;
	for (int i = 0; i < pushV.size(); i++)//模仿正常的压入，出栈顺序，要是temp为空，则popV是出栈顺序
	{
		temp.push(pushV[i]);
		while (!temp.empty() && temp.top() == popV[j])
		{
			temp.pop();
			j++;
		}
	}
	return temp.empty();
}