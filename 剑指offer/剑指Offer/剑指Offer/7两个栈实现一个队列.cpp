#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);//����Ҫ�ж�stack1�Ƿ���ֵ
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
			//for(int i=0;i<count;i++)//����������ʽ��Ϊstack1.size()����pop()�ڼ�С������������һ������count
			//{
			//stack2.push(stack1.top());
			//stack1.pop();
			//}

		}

		if (stack2.empty())//���ڴ˴���stack2ҪΪ�գ���stack1Ҳһ��Ϊ�ա�
			return -1;
		temp = stack2.top();//top()��pop()���߳ɶԳ��֣�top����ջ��Ԫ�أ�pop()ɾ��ջ��Ԫ��
		stack2.pop();
		return temp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};