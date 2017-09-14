/*
ip ����:����ʼ��ͽ������н��棬�����ָ���
���룺
1.1.1.1				//ip1��ʼ��
255.255.255.255		//ip2������
2.2.2.2				//ip2��ʼ��
3.3.3.3				//ip2��ʼ��
�����
Overlap IP
*/
#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<string> split_str_33(const string &s, const string &seperator) {
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

bool OverLap(vector<string> str1, vector<string> str2, vector<string> str3, vector<string> str4) {

	if (str1[0]>str4[0]||str2[0]<str3[0])
	{
		return false;
	}
	if (str1[1] > str4[1] || str2[1] < str3[1])
	{
		return false;
	}
	if (str1[2] > str4[2] || str2[2] < str3[2])
	{
		return false;
	}
	if (str1[3] > str4[3] || str2[3] < str3[3])
	{
		return false;
	}
	return true;
}
//ip ����:����1
int main_33_1_1() {
	
	string strip1,strip2,strip3,strip4;
	cin >> strip1 >> strip2 >> strip3 >> strip4;
	vector<string> str1 = split_str_33(strip1, ".");
	vector<string> str2 = split_str_33(strip2, ".");
	vector<string> str3 = split_str_33(strip3, ".");
	vector<string> str4 = split_str_33(strip4, ".");
	bool result = OverLap(str1, str2, str3, str4);
	if (result)
	{
		cout << "Overlap IP" << endl;
	}
	else {
		cout << "No Overlap IP" << endl;
	}
	//cout << str4[3] << endl;
	return 0;
}

//ip ����:����2
#include<iostream>
#include<string>
using namespace std;

int main_33_1_2()
{
	string begin1, end1, begin2, end2;
	while (cin >> begin1 >> end1 >> begin2 >> end2)
	{
		if ((begin2 >= begin1&&begin2 <= end1) || (end2 >= begin1&&end2 <= end1))
			cout << "Overlap IP" << endl;
		else
			cout << "No Overlap IP" << endl;
	}
	return 0;
}

/*
�����ӷ�ת��
����
-12345
���
5			//�����ĸ���
-1 2 3 4 5  //�����������
-54321  //�����������
*/
#include<iostream>
#include <string>
#include <sstream>
using namespace std;
int main_33_2()
{

	int n;
	stringstream temp;
	string strtemp;
	cin >> n;
	temp << n;
	temp >> strtemp;
	string strsub;
	if (strtemp[0] != '-')
	{
		cout << strtemp.size() << endl;
		for (int i = 0; i < strtemp.size(); ++i)
		{
			if (i != strtemp.size() - 1)
			{
				cout << strtemp[i] << " ";
			}
			else
				cout << strtemp[i] << endl;
		}
		for (int j = strtemp.size() - 1; j >= 0; --j)
		{
			cout << strtemp[j];
		}
	}
	else
	{
		cout << strtemp.size() - 1 << endl;
		cout << strtemp[0];
		for (int i = 1; i < strtemp.size(); ++i)
		{
			if (i != strtemp.size() - 1)
			{
				cout << strtemp[i] << " ";
			}
			else
				cout << strtemp[i] << endl;
		}
		cout << strtemp[0];
		for (int j = strtemp.size() - 1; j > 0; --j)
		{
			cout << strtemp[j];
		}
	}
	cout << endl;
	return 0;
}
/*
����һ���ַ������������֣�ʹ�ÿո�ָҪ����������������3λֱ�����򣬴�����λ����ȡ����λ��������
����С���󣬲��������С������n����
����
22 2016 1213 1232
3           //����С�Ŀ�ʼ��������
���
1213
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main()
{
	string strtemp;
	int index;
	getline(cin, strtemp);
	cin >> index;

	istringstream sstr(strtemp);
	int temp = 0;
	vector <int> numbers;
	while (sstr >> temp)
	{
		numbers.push_back(temp);
	}
	multimap<int, int> map_temp;
	for (int i = 0; i < numbers.size(); i++)
	{
		map_temp.insert(make_pair(numbers[i]%1000, numbers[i]));
	}
	vector<int> result;
	for (auto it = map_temp.begin(); it != map_temp.end(); ++it)
	{
		result.push_back(it->second);
	}
	cout << result[index - 1] << endl;
	return 0;
}


