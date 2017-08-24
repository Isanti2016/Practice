/*
如abc
最少的回文个数是3，a,b,c
acc的最少回文个数是1，cac
实质是统计奇数字母的个数
*/
#include <iostream>
#include <string>
#include <algorithm>
//#include <string.h>

using namespace std;

int main_2() {
	int result = 0;
	string str;
	cin >> str;
	int count[26];
	//for (int i = 0; i < 26; ++i) {
	//	count[i] = 0;
	//}
	memset(count, 0, sizeof(count[0]));
	for (int i = 0; i < str.size(); ++i) {
		count[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i) {
		if (count[i] & 1 != 0)
			result++;
	}
	cout << result << endl;
	return 0;
}
