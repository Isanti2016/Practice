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
	string str;
	string password;
	cin >> str >> password;
	if (password.length() < 8 || (password == str))
	{
		cout << 0 << endl;
	}
	else
	{
		reverse(str.begin(), str.end());
		if (str == password)
		{
			cout << 0 << endl;
		}
		else
		{
			int cnt[4] = { 0,0,0,0 };
			for (int i = 0; i < password.size(); ++i)
			{
				if (password[i] >= '0' && password[i] <= '9')
				{
					cnt[0]++;
				}
				else  if (password[i] >= 'A' && password[i] <= 'Z')
				{
					cnt[2]++;
				}
				else  if (password[i] >= 'a' && password[i] <= 'z')
				{
					cnt[1]++;
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
			if (number == 2)
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
			else if (number <= 1)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << 3 << endl;
			}
		}
	}
	return 0;
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
��һ������ԭʼ�ַ��� �ָ�����ԭʼ�ַ����ͷָ����ո�ֿ�(�ָ����в�������ո�)
*/
vector<string> split_str_34(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//�ҵ��ַ������׸������ڷָ�������ĸ��
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {
					++i;
					flag = 0;
					break;
				}
		}
		//�ҵ���һ���ָ������������ָ���֮����ַ���ȡ����
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}
int main_34_3() {
	string str, oper;
	cin >> str >> oper;
	vector<string> result;
	result = split_str_34(str, oper);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	return 0;

}