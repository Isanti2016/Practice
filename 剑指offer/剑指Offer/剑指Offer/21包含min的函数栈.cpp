#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "Common_head.h"

using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b));

/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
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