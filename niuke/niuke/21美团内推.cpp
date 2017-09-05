#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main_21()
{
	int n = 0;
	cin >> n;
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	if (input.empty())
	{
		return 0;
	}
	int maxnum = 0; // 最大组数
	for (int i = 0; i < n; ++i)
	{
		if (maxnum < input[i])
		{
			maxnum = input[i];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (maxnum == input[i])
		{
			input[i] = 0;
			break;
		}
	}
	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		total += input[i];
	}
	if (maxnum > total)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}
	return 0;
}