#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "Common_head.h"

using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b));

/*
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

stack<pair<int, int>> m_data;
void push(int value) {
	int min_temp = 0;
	if (m_data.empty())
		min_temp = value;
	else
		min_temp = MIN(value, m_data.top().second);
	pair<int, int> data(value, min_temp);
	m_data.push(data);
}
void pop() {
	m_data.pop();
}
int top() {
	return m_data.top().first;
}
int min() {
	return m_data.top().second;
}