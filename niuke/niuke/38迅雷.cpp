/*
将一个整数反转
输入
123
-123
200
输出
321
-321
2
*/
#include<iostream>
#include <string>
#include <sstream>
using namespace std;
int main_38_1()
{

	int n;
	stringstream temp;
	string strtemp;
	cin >> n;
	if (n == 0 || n == -1)
		cout<<0<<endl;
	temp << n;
	temp >> strtemp;

	if (strtemp[0] != '-')
	{
		bool flag = true;
		for (int j = strtemp.size() - 1; j >= 0; --j)
		{
			if (flag&&strtemp[j]!='0')
			{
				flag = false;
			}
			if(!flag)
				cout << strtemp[j];
		}
	}
	else
	{
		bool flag = true;
		cout << strtemp[0];
		for (int j = strtemp.size() - 1; j > 0; --j)
		{
			if (flag&&strtemp[j] != '0')
			{
				flag = false;
			}
			if (!flag)
				cout << strtemp[j];
		}

	}
	cout << endl;
	return 0;
}

/*
输入两个整数 n 和 m，从数列 1，2，3.......n 中 随意取几个数,
使其和等于 m ,要求将其中所有的可能组合列出来.
*/

#include <iostream>
using namespace std;

int FindCombine(int n, int m)
{
	int method=0;
	int record[120]; //存储组合当前的取值
	for (int i = 0; i < 120; i++)
	{
		record[i] = i + 1;
	}
	int num = 0; //组合中数字的个数
	int sum = 0; //组合中数字加起来的和

	while (sum < m)
	{
		sum += record[num];
		num++;
		if (sum == m)
		{
			method++;
			if (num == 1)
			{
				return method;
			}
		}
		if ((sum >= m) || (sum < m && record[num - 1] == n && num >= 2)) //如果大小超过m 或者 最后一个数字大小等于n 更新record
		{
			num--;
			sum -= record[num];
			num--;
			sum -= record[num];
			if (record[num] <= n)
			{
				record[num]++;
				for (int i = 1; i <= n - record[num]; i++)
				{
					record[i + num] = record[num] + i;
				}
			}
		}
		else if (sum < m && record[num - 1] == n && num == 1)
		{
			return method;
		}
	}
	return method;
}



int main_38_2()
{
	int n, m;
	cin >> n >> m;
	if (m<=0)
	{
		cout << 0 << endl;
	}
	int method=0;
    method = FindCombine(n,m);
	cout << method << endl;
	return 0;
}

