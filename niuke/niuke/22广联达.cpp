//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//int n, m;// size = n*m
//const int direction[][2] = { { 1, 0 },{ 0, -1 },{ 0, 1 },{ -1, 0 } };
//
//bool check_22(int x, int y, vector < vector  < int> >& I)
//{
//	if (x >= 0 && x < n && y >= 0 && y < m && I[x][y] == 1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool DFS_22(int x, int y, int label, vector <vector <int> >& input)
//{
//	if (1 != input[x][y])
//	{
//		return false;
//	}
//	else
//	{
//		input[x][y] = label;
//
//		for (int i = 0; i < 4; i++)
//		{
//			if (check_22(x + direction[i][0], y + direction[i][1], input))
//			{
//				DFS_22(x + direction[i][0], y + direction[i][1], label, input);
//			}
//		}
//
//	}
//	return true;
//}
//
//
//int main_22()
//{
//	int res;
//	int rows = 0;
//	int cols = 0;
//	cin >> rows >> cols;
//	n = rows;
//	m = cols;
//	vector < vector  < int> > M(rows);
//	for (int x = 0; x < rows; x++)
//	{
//		for (int y = 0; y < cols; y++)
//		{
//			int temop;
//			cin >> temop;
//			M[x].push_back(temop);
//		}
//	}
//
//	int label = 2;
//	for (int i = 0; i < rows; ++i)
//	{
//		for (int j = 0; j < cols; ++j)
//		{
//			if (DFS_22(i, j, label, M))
//			{
//				label++;
//			}
//		}
//	}
//
//	res = label - 2;
//	cout << res << endl;
//	return 0;
//}
#include <iostream>
#include <vector>
using namespace std;
/*
在长度为n+1的数组中包含1到n的中间的整数，至少有一个是重复的，在不修改数组的条件下，怎么找到这个数。
*/
int Search_repeat(const vector<int>& vec) {
	int result=0;
	int length = vec.size();
	int *a = new int[length + 1];
	memset(a, 0, (length + 1)*sizeof(int));
	for (int i = 0; i < vec.size();++i)
	{
		a[vec[i]]++;
		if (a[vec[i]]>1)
		{
			result = vec[i];
			break;
		}
	}
	return result;
}
int main() {
	vector<int> vec = { 1,2,3,5,2,3,2};
	int result = Search_repeat(vec);
	cout << result<< endl;
	return 0;
}