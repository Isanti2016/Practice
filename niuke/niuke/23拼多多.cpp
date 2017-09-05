#include <iostream>
#include <vector>
#include <algorithm>
/*
С�ܰ�ս�����Ա���
���룺
2 5                  //2��С�ܣ�5������
5 6 10 20 30         //5�����ɿ��Բ��������
4 34			     //ս����Ϊ4��С���ȳ����ı��ɣ������ܳԳ�
3 35                 //ս����Ϊ3��С�ܺ�����ı��ɣ������ܳԳţ����ԳԶ��
�����
4                   //С�ܻ�ȱ�ٶ�������
0
*/
using namespace std;

int main_23()
{
	int n, m;
	cin >> n;
	cin >> m;
	vector<int> vec;
	while (m>0)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
		m--;
	}
	sort(vec.begin(), vec.end());

	vector <vector  < int>> Bear(n);
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			int temp;
			cin >> temp;
			Bear[x].push_back(temp);
		}
	}

	for (int i = 0; i < Bear.size();++i)
	{
		for (int j = 0; j < Bear[0].size();++j)
		{
			cout << Bear[i][j] << " ";
		}
		cout << endl;
	}
	vector<int> result;
	for (int i = 0; i < n;++i)
	{
		int count = 0;
		for (int j = vec.size()-1; j >= 0;j--)
		{
			if ((count + vec[j])<=Bear[i][1] && vec[j]!=-1)
			{
				count = count + vec[j];
				vec[j] = -1;
			}
		}
		result.push_back(Bear[i][1] - count);
	}
	for (int i = 0; i < result.size();++i)
	{
		cout << result[i] << endl;
	}
	return 0;
}