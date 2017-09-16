#include <iostream>
#include <vector>
#include "Common_head.h"
/*
˳ʱ���ӡ�����ص�ʹ��һ��start�������ƴ�ӡ��ʹ��i<row*column���ƴ�ӡ����
*/
vector<int> printMatrix(vector<vector<int> > matrix) {
	int row = matrix.size();
	int column = matrix[0].size();
	vector<int> result;
	int i = 0, start = 0;
	while (i < (row*column))
	{
		int endx = column - start - 1;
		int endy = row - start - 1;
		//�����ң�����=endxʱ��Ҫ�Ǿ��Σ�ÿһ���ߴ�ӡ������ͬ���������һ��Ԫ�أ��޷���ӡ
		for (int a = start; (a <= endx) && i < (row*column); a++)
		{
			result.push_back(matrix[start][a]);
			i++;
		}
		//���ϵ���
		for (int a = start + 1; (a <= endy) && i < (row*column); a++)
		{
			result.push_back(matrix[a][endx]);
			i++;
		}
		//���ҵ���
		for (int a = endx - 1; (a >= start) && i < (row*column); a--)
		{
			result.push_back(matrix[endy][a]);
			i++;
		}
		//���µ���
		for (int a = endy - 1; (a > start) && i < (row*column); a--)
		{
			result.push_back(matrix[a][start]);
			i++;
		}
		start++;
	}
	return result;
}