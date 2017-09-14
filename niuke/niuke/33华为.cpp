/*
ip 覆盖:即起始点和结束点有交叉，即出现覆盖
输入：
1.1.1.1				//ip1起始点
255.255.255.255		//ip2结束点
2.2.2.2				//ip2起始点
3.3.3.3				//ip2起始点
输出：
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
		//找到字符串中首个不等于分隔符的字母；
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
		//找到又一个分隔符，将两个分隔符之间的字符串取出；
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
//ip 覆盖:方法1
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

//ip 覆盖:方法2
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
整数子反转：
输入
-12345
输出
5			//整数的个数
-1 2 3 4 5  //单个正序输出
-54321  //单个反序输出
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
输入一个字符串仅包含数字，使用空格分割，要求对其进行排序，少于3位直接排序，大于三位，则取后三位参与排序。
按从小到大，并输出从最小的数第n个数
输入
22 2016 1213 1232
3           //从最小的开始第三个数
输出
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


