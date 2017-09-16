#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
密码分为4个等级
等级0，密码小于8位/密码与用户名一样或相反/包含4类字符中的任一类
等级1，密码大于等于8位包含两类字符，且组合为（数字和小写字母）或（数字+大写字母）
等级2，密码大于等于8位包含两类字符，且组合不能为（数字和小写字母）或（数字+大写字母）
等级3，密码等于8位包含三类以上的字符。
输入：用户名+密码
admin 112233
0
*/
int main_34_1()
{
	string user;
	string Mima;
	cin >> user >> Mima;

	if (Mima.length() < 8 || (Mima == user))
	{
		cout << 0 << endl;
	}
	else
	{
		reverse(user.begin(), user.end());
		if (user == Mima)
		{
			cout << 0 << endl;
		}
		else
		{
			int cnt[4] = { 0,0,0,0 };
			for (int i = 0; i < Mima.size(); ++i)
			{
				if (Mima[i] >= '0' && Mima[i] <= '9')
				{
					cnt[0]++;
				}
				else  if (Mima[i] >= 'a' && Mima[i] <= 'z')
				{
					cnt[1]++;
				}
				else  if (Mima[i] >= 'A' && Mima[i] <= 'Z')
				{
					cnt[2]++;
				}
				else
				{
					cnt[3]++;
				}

			}
			int number = 0;
			for (int i = 0; i < 4; ++i)
			{
				if (cnt[i] != 0)
				{
					number++;
				}
			}

			if (number <= 1)
			{
				cout << 0 << endl;
			}
			else   if (number == 2)
			{
				if ((cnt[0] && cnt[1]) || (cnt[0] && cnt[2]))
				{
					cout << 1 << endl;
				}
				else
				{
					cout << 2 << endl;
				}
			}
			else
			{
				cout << 3 << endl;
			}

		}
	}
	return 0;
}