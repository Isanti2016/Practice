/*
��ά�����в���
1 2 8 9 
2 4 9 12
4 7 10 13
6 8 11 15
7
���
true;
*/
#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int> > array)
{
	int rowCount = array.size();//��
	int colCount = array[0].size();//��
	int i, j;
	for (i = rowCount - 1, j = 0; i >= 0 && j < colCount;)
	{
		if (array[i][j] == target)
			return true;

		if (array[i][j] > target)
			i--;
		if (array[i][j] < target)
			j++;
	}
	return false;
}