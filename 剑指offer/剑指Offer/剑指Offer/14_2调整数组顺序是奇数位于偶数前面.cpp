#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
��������˳��������λ��ż��ǰ��,����������ż�������λ�ò��䡣
*/

void reOrderArray(vector<int> &array) {
	if (array.size() == 0)
	{
		return;
	}
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] & 1)//Ϊ����
		{
			int temp = array[i];
			int j = i - 1;
			while (!(array[j] & 1) && j >= 0)//���ò�������,Ҫע��j>=0,��Ȼj--����Խ��
			{
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = temp;
		}

	}
}
/*
��������˳��������λ��ż��ǰ�档
*/
void reOrderArray_1(vector<int> &array) {
	if (array.size() == 0)
	{
		return;
	}
	int pbegin = 0, pend = array.size() - 1;
	while (pbegin<pend)
	{
		while (pbegin < pend && (array[pbegin] & 1 != 0))//����ƶ���ֱ��ָ��һ��ż��
			pbegin++;
		while (pbegin<pend&&(array[pbegin]&&1)==0)//��ǰ�ƶ���ֱ��ָ��һ������
			pend--;
		if (pbegin<pend)
		{
			swap(array[pbegin],array[pend]);
		}
	}
}