#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;
static int cmp(const string str1, const string str2)
{
	string s1 = str1 + str2;
	string s2 = str2 + str1;

	return s1 < s2;
}

string PrintMinNumber(vector<int> numbers) {
	vector<string> vec;
	string result = "";
	int length = numbers.size();
	if (length == 0)
		return result;

	for (int i = 0; i < length; i++)
	{
		stringstream ss;//利用stringstream把int转为string
		string str;
		ss << numbers[i];
		ss >> str; //利用stringstream把int转为string
		vec.push_back(str);
	}

	sort(vec.begin(), vec.end(), cmp);//调用algorithm中的sort算法进行排序

	for (int i = 0; i < length; i++)
	{
		result += vec[i];
	}

	return result;//组成字符串
}
