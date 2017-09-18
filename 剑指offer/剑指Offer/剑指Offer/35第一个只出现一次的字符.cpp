#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

/*
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/
int FirstNotRepeatingChar(string str) {
	int result;
	int length = str.size();
	if (length == 0)
		return -1;
	int hash[256];
	memset(hash, 0, sizeof(int) * 256);
	for (int i = 0; i < length; i++) {
		hash[str[i]]++;        //统计每个字符出现的次数
	}
	int j = 0;
	while (j < length) {
		if (hash[str[j]] == 1)//按照str出现的顺序统计第一个出现一次的字符
		{
			result = j;
			break;
		}
		j++;
	}
	return result;
}