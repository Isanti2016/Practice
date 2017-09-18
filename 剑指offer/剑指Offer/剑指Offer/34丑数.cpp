#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;
/*
丑数：包含因子2，3，5的整数，习惯上把1当为第一个丑数
求第1500个丑数
*/
int Min_Number(int num1, int num2, int num3)//找出三者中最小的数
{
	int min_num = (num1 < num2) ? num1 : num2;
	min_num = (min_num < num3) ? min_num : num3;
	return min_num;
}

int GetUglyNumber_Solution(int index) {
	if (index <= 0)
		return 0;
	int* UglyNumber = new int[index];//动态建立一个index长的数组
	UglyNumber[0] = 1;//把1当作第一个丑数
	int *Number2 = UglyNumber;//利用指针方便进行访问
	int *Number3 = UglyNumber;
	int *Number5 = UglyNumber;
	int count = 1;

	while (count < index)
	{
		int min_num = Min_Number(*Number2 * 2, *Number3 * 3, *Number5 * 5);
		UglyNumber[count] = min_num;

		while (UglyNumber[count] >= *Number2 * 2)//把已有数组中的数进行成倍增长
			Number2++;                      //指针记录一直维护一个位置
		while (UglyNumber[count] >= *Number3 * 3)
			Number3++;
		while (UglyNumber[count] >= *Number5 * 5)
			Number5++;
		count++;
	}
	return UglyNumber[index - 1];
}
