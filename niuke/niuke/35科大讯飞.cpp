#include<iostream>
#include<string>
#include<vector>
#include <set>
#include<map>


using namespace std;
/*
����RLLR�ĸ��˵Ķ��У�RL�����������ģ����ܻ���LLR����RLR�������RLRʱ�������һ�����LR����RR���ҵ�����������ʣ�µ�����
����
LRRLRL
���
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
����
����пγ̳�ͻ�����YES����û�����������г�ͻ�Ŀγ�ʱ�����ţ�������һ��ʱ���Ӧ�����ŵ����
��ʱ����ͬ�Ĵ���multimap�У�����ʱ���С���������עmultimap����һ��key�����val
5
01 204521    //01������1��1�㣬204521����γ����
23 204523    //23������3��3��
22 204526
01 204528
22 204527
���
01 204521 204528
22 204526 204527
*/
void PrintResult(vector<vector<int>>& vec) {
	int a[50];
	multimap<int, int> result;//һ��key�����val�����Һ�vectorһ����Ч����������������������������������������
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
			//temp.insert(vec[i][0]);//������������ܹ��м�����ͻ��
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




