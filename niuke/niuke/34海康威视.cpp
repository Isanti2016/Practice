#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
�����Ϊ4���ȼ�
�ȼ�0������С��8λ/�������û���һ�����෴/����4���ַ��е���һ��
�ȼ�1��������ڵ���8λ���������ַ��������Ϊ�����ֺ�Сд��ĸ��������+��д��ĸ��
�ȼ�2��������ڵ���8λ���������ַ�������ϲ���Ϊ�����ֺ�Сд��ĸ��������+��д��ĸ��
�ȼ�3���������8λ�����������ϵ��ַ���
���룺�û���+����
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