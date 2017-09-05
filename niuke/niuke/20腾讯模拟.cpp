#include <iostream>
#include <vector>

using namespace std;

/*
�������������в��������ڵ����С�����ĸ��ڵ�
�����������Ԫ���ڶ��ֽڵ�����ʱ����ǰ�Ķ��ֽڵ����Ҫ���ҵ���С�����ĸ��ڵ㡣ʵ����ֻҪ��������СԪ�ص��м䣬��Ϊ���ֽڵ�
���룺4 10 15 13
�����12



*          8
*        /   \
*       4     12
*      / \   /   \
*     2  6   10   14
*    /\  /\  / \ /  \
*   1 3 5 7 9 11 13 15
*/

int Min_Sort_Tree_CommentOfTree(int low, int high, int min1, int max1) {
	int result=0;
	while (low<high)
	{
		int mid = (low + high) / 2;
		if (mid<=min1)
		{
			low = mid + 1;
		}
		if (mid>=max1)
		{
			high = mid - 1;
		}
		if (mid>=min1&&mid<=max1)
		{
			result = mid;
			break;
		}
	}
	return result;
}
int main_20() {
	int k, num1, num2, num3;
	cin >> k;
	cin >> num1;
	cin >> num2;
	cin >> num3;
	int min1 = num1 < num2 ? num1 : num2;//��ʹ������������С��һ����
	min1 = min1 < num3 ? min1 : num3;

	int max1 = num1 > num2 ? num1 : num2;//��ʹ��������������һ����
	max1 = max1 > num3 ? max1 : num3;

	int low = 1;
	int high = 2 << k - 1;
	int result = Min_Sort_Tree_CommentOfTree(low,high,min1,max1);
	cout << result << endl;
	return 0;
}