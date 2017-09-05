#include <iostream>
#include <vector>

using namespace std;


int n, m;// size = n*m
const int direction[][2] = { { 1, 0 },{ 0, -1 },{ 0, 1 },{ -1, 0 } };

bool check_22(int x, int y, vector < vector  < int> >& I)
{
	if (x >= 0 && x < n && y >= 0 && y < m && I[x][y] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DFS_22(int x, int y, int label, vector <vector <int> >& input)
{
	if (1 != input[x][y])
	{
		return false;
	}
	else
	{
		input[x][y] = label;

		for (int i = 0; i < 4; i++)
		{
			if (check_22(x + direction[i][0], y + direction[i][1], input))
			{
				DFS_22(x + direction[i][0], y + direction[i][1], label, input);
			}
		}

	}
	return true;
}


int main_22()
{
	int res;
	int rows = 0;
	int cols = 0;
	cin >> rows >> cols;
	n = rows;
	m = cols;
	vector < vector  < int> > M(rows);
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			int temop;
			cin >> temop;
			M[x].push_back(temop);
		}
	}

	int label = 2;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (DFS_22(i, j, label, M))
			{
				label++;
			}
		}
	}

	res = label - 2;
	cout << res << endl;
	return 0;
}
