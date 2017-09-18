#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;

/*
随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,大\小王可以看成任何数字算0,并且A看作1,J为11,Q为12,K为13
*/

bool IsContinuous(vector<int> numbers) {
	int length = numbers.size();
	if (length != 5)//凡是不是五张牌，都是不符合题意的。
		return false;
	sort(numbers.begin(), numbers.end());//stl中algorithm
										 //qsort(&numbers,length,sizeof(numbers[0]),Comp);//函数库stdlib.h中的函数
	int num_zero = 0;
	int count_abs = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		//if(num_zero==length-1)//为防止越界，特殊情况4个0，即可
		//return true;
		if (numbers[i] == 0)
			num_zero++;
		else {
			int absent = numbers[i + 1] - numbers[i];
			if (absent == 0)//含有重复的数，一定是非连续的顺子
				return false;
			if (absent > 1)
				count_abs += (absent - 1);
		}
	}
	return (num_zero >= count_abs) ? true : false;
}