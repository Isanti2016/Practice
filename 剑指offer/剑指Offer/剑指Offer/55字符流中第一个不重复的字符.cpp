#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	Solution() :index(0) {
		memset(num, -1, sizeof(num[0]) * 256);
	}
	void ��
		
		
		(char ch)
	{
		if (num[ch] == -1)//��һ�β���
			num[ch] = index;
		else if (num[ch] >= 0)//��β���
			num[ch] = -2;
		index++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		char result = '#';
		int i = 0;
		int min_index = 0x7fffffff;
		while (i < 256) {
			if (num[i] >= 0 && num[i] < min_index)
			{
				result = (char)i;//ǿ��ת��
				min_index = num[i];
			}
			i++;
		}
		return result;
	}
private:
	int index;
	int num[256];
};