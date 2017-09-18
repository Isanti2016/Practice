#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

/*
��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
*/
int FirstNotRepeatingChar(string str) {
	int result;
	int length = str.size();
	if (length == 0)
		return -1;
	int hash[256];
	memset(hash, 0, sizeof(int) * 256);
	for (int i = 0; i < length; i++) {
		hash[str[i]]++;        //ͳ��ÿ���ַ����ֵĴ���
	}
	int j = 0;
	while (j < length) {
		if (hash[str[j]] == 1)//����str���ֵ�˳��ͳ�Ƶ�һ������һ�ε��ַ�
		{
			result = j;
			break;
		}
		j++;
	}
	return result;
}