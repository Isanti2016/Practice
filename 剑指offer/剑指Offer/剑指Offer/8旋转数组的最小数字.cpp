
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int Min(vector<int> vec);

int minNumberInRotateArray(vector<int> rotateArray) {
	if (rotateArray.size() == 0)
		return -1;
	int low = 0, high = rotateArray.size() - 1;
	int mid = low;
	while (rotateArray[low] >= rotateArray[high])//�ж��Ƿ�Ϊ�������飬���򷵻ص�һ��ֵ
	{
		if (low == high - 1)//�������1�򷵻�
		{
			mid = high;
			break;
		}
		mid = (low + high) / 2;
		if (rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high])//�޷��ж�λ��ǰ��������Ǻ������
			return Min(rotateArray);
		if (rotateArray[low] <= rotateArray[mid])//ǰ���������
			low = mid;
		if (rotateArray[mid] <= rotateArray[high])//�����������
			high = mid;
	}
	return rotateArray[mid];
}
int Min(vector<int> vec)
{
	int temp = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] < temp)
			temp = vec[i];
	}
	return temp;
}