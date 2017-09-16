#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Common_head.h"

using namespace std;

/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No��
*/
bool Verify(vector<int> sequence)
{
	int length = sequence.size();
	if (length == 0 || length == 1)//�ݹ�ʱΪ0��1�������ݹ��־
		return true;
	vector<int> left_sque;
	vector<int> right_sque;

	int root = sequence[length - 1];

	bool flag = false;

	for (int i = 0; i < length - 1; i++)
	{
		if (sequence[i] < root)//������벿��
		{
			if (flag)//�ȴ��ں�С�ڲ����κζ����������ĺ������
				return false;
			left_sque.push_back(sequence[i]);

		}

		if (sequence[i] > root)//�����Ұ벿��
		{
			right_sque.push_back(sequence[i]);
			flag = true;
		}

	}
	return Verify(left_sque) && Verify(right_sque);

}

bool VerifySquenceOfBST(vector<int> sequence) {
	int length = sequence.size();
	if (length == 0)//��һ��Ϊ0�������κζ����������ĺ������
		return false;
	bool result = Verify(sequence);
	return result;

}
