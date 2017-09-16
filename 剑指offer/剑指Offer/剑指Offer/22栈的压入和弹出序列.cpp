#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����
1,2,3,4,5
4��5,3,2,1
���
true
*/

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	if (pushV.size() != popV.size())
		return false;
	if (pushV.empty() || popV.empty())
		return false;
	stack<int> temp;
	int j = 0;
	for (int i = 0; i < pushV.size(); i++)//ģ��������ѹ�룬��ջ˳��Ҫ��tempΪ�գ���popV�ǳ�ջ˳��
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