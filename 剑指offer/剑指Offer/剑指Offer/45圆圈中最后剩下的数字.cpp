#include <iostream>
#include <vector>
#include <algorithm>
#include "Common_head.h"

using namespace std;
/*
��0��1��2��3....n-1�ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��ɾ����m�����ӣ���ԲȦ��ʣ�µ����һ�����֡�
*/

int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; ++i)//��i=1��ʱ�����ʣ�µ�һ����0
	{
		last = (last + m) % i;
	}
	return last;//Ҫ�Ǵ�1��ʼ�ų�һ��Բ��ֱ��return last+1����
}