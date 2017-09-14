#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);//不需要判断stack1是否有值
	}

	int pop() {
		int temp;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			//int count=stack1.size();
			//for(int i=0;i<count;i++)//不用这种形式因为stack1.size()随着pop()在减小，除非像上面一样定义count
			//{
			//stack2.push(stack1.top());
			//stack1.pop();
			//}

		}

		if (stack2.empty())//放在此处，stack2要为空，则stack1也一定为空。
			return -1;
		temp = stack2.top();//top()和pop()两者成对出现，top返回栈顶元素，pop()删除栈顶元素
		stack2.pop();
		return temp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};