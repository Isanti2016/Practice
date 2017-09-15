#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reOrderArray(vector<int> &array) {
	if (array.size() == 0)
	{
		return;
	}
	int begin = 0, end = array.size() - 1;
	while (begin<end)
	{
		while (begin < end && (array[begin] & 1 != 0))//����ƶ���ֱ��ָ��һ��ż��
			begin++;
		while (begin<end&&(array[begin]&&1)==0)//��ǰ�ƶ���ֱ��ָ��һ������
			end--;
		if (begin<end)
		{
			swap(array[begin],array[end]);
		}
	}
}