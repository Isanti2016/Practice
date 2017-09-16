#include<iostream>
#include<string>
#include<vector>
#include <set>
#include<map>


using namespace std;
/*
队列RLLR四个人的队列，RL是面对面对立的，可能会变成LLR或者RLR，而变成RLR时，还会进一步变成LR或者RR。找到队列中最少剩下的人数
输入
LRRLRL
输出
2
*/
bool Comp(string &str) {
	bool result = true;
	for (int i = 0; i < str.size() - 1; ++i) 
	{
		if (str[i] == 'R'&&str[i + 1] == 'L') 
		{
			result = false;
			if (i == str.size() - 2)
			{
				if (str[i - 1] == 'R')
					str.erase(i, 1);
				else
					str.erase(i + 1, 1);
			}
			else if (i == 0) 
			{
				if (str[i + 1] == 'L')
					str.erase(i + 1, 1);
				else
					str.erase(i, 1);
			}
			else 
			{
				if (str[i - 1] == 'R')
					str.erase(i, 1);
				else if (str[i + 2] == 'L')
					str.erase(i + 1, 1);
				else 
					str.erase(i + 1, 1);
			}
			break;
		}

	}
	return result;
}

int main_35_1()
{
	string str_temp;
	while (cin >> str_temp) {
		while (!Comp(str_temp));
		cout << str_temp.size();

	}
	return 0;
}


/*
输入
如果有课程冲突输出“YES”，没有则输出输出有冲突的课程时间和序号，并且是一个时间对应多个序号的输出
把时间相同的存入multimap中，按照时间从小到大输出，注multimap可以一个key，多个val
5
01 204521    //01代表周1，1点，204521代表课程序号
23 204523    //23代表周3，3点
22 204526
01 204528
22 204527
输出
01 204521 204528
22 204526 204527
*/
void PrintResult(vector<vector<int>>& vec) {
	int a[50];
	multimap<int, int> result;//一个key，多个val，并且和vector一样的效果！！！！！！！！！！！！！！！！！！！
	//set<int> temp;
	for (int i = 0; i < 50;++i)
	{
		a[i] = 0;
	}

	for (int i = 0; i < vec.size();++i)
	{
		a[vec[i][0]]++;
	}
	for (int i = 0; i < vec.size();++i)
	{
		if (a[vec[i][0]]>1)
		{
			result.insert(make_pair(vec[i][0], vec[i][1]));
			//temp.insert(vec[i][0]);//可以用于输出总共有几个冲突的
		}
	}
	//cout << temp.size() << endl;
	if (result.size()==0)
	{
		cout << "YES" << endl;
	}
	else 
	{
		for (int i = 0; i < 50; ++i)
		{
			if (a[i] > 1)
			{
				if (i <= 9)
					cout << 0;
				multimap<int, int>::iterator beg, end, k;
				beg = result.lower_bound(i);
				end = result.upper_bound(i);
				cout << beg->first << " ";
				for (k = beg; k != end; k++)
				{
					cout << k->second<<" " ;
				}
				cout << endl;
			}
		}
	}
}

int main_35_2() {
	int n;
	cin >> n;
	vector<vector<int>> vec;
	while (n > 0) {
		vector<int> vec_1;
		int m = 2;
		while (m > 0) {
			int temp;
			cin >> temp;
			vec_1.push_back(temp);
			m--;
		}
		n--;
		vec.push_back(vec_1);
	}
	PrintResult(vec);
	return 0;
	cout << vec.size() << endl;
}




