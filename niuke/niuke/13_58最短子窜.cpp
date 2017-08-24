/*
58 王者荣耀战斗力
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int Com_num(int num1, int num2) {
//	if (num1 == 0 || num2 == 0)
//	{
//		return -1;
//	}
//	int z = num2;
//	while (num1%num2)
//	{
//		z = num1%num2;
//		num1 = num2;
//		num2 = z;
//	}
//	return z;
//}
//int main() {
//	int x, n;
//	vector<int> vec;
//	cin >> x;
//	cin >> n;
//	while (n>0)
//	{
//		int temp;
//		cin >> temp;
//		vec.push_back(temp);
//		--n;
//	}
//	for (int i = 0; i < vec.size();++i)
//	{
//		if (vec[i]<=x)
//		{
//			x = x + Com_num(x, vec[i]);
//			
//		}
//		else {
//			x = x + vec[i];
//		}
//	}
//	cout << "x:" << x << endl;
//	return 0;
//}
/*
58 最小字符串的长度，不要求有序
例如happywhubacc与wbau 最短的的是5
*/
#include<stdio.h>  
#include<stdlib.h>  
#include<iostream>  
#include<string.h>  
#include<string>  
#include <limits.h>  
using namespace std;

int hashs[256];
int getMin_str(char str[], int length1, char src[],int length2)
{
	for (int i = 0; i < 256;++i)
	{
		hashs[i] = -1;
	}
	for (int i = 0; i < length1;++i)
	{
		hashs[str[i]] = 0;
	}
	int count = 0;
	int Min_len = 0x7fffffff;
	int i,j=0;
	for (i = 0; i < length2&&(count<length1); ++i)
	{
		if (hashs[src[i]] != -1) {
			if (hashs[src[i]] == 0)
				count++;
			hashs[src[i]]++;
		}
	}

	if (src[i]=='\0'&&(count<length1))//没找到或没找全要统计的字符
	{
		return -1;
	}
	bool flag = false;
	while ((j < length2)&&(i<length2))
	{
		if (hashs[src[j]]>1)//要统计的字符中最前面一个字符有多个，可以继续向前走
		{
			hashs[src[j]]--;
			j++;
		}
		else if(hashs[src[j]]==-1) {//不是要统计的字符，继续向前走
			j++;
		}
		else if (hashs[src[j]]==1)//要统计的字符中最前面一个字符仅有一个
		{
			if (hashs[src[i]]!=-1)//找到要统计的字符，继续统计
			{
				hashs[src[i]]++;
			}
			if (src[i]==src[j])//要统计的字符中最前面一个字符和后面一个字符相等，两者同时移动
			{
				j++;
				hashs[src[i]]--;
				if (i == length2 - 1) {//最后一位正好为前面要查找的字符是，为了便于j继续变换，此时i占时停留
					flag = true;
					continue;
				}

			}
			i++;//此条件hashs[src[j]]==1就是为移动i++准备
		}
		int temp = flag ? (i - j + 1) : i - j;//flag为真即最后一位正好为前面要查找的字符，此时要用+1计算长度
		if (Min_len > temp)//求最短距离
		{
			Min_len = temp;
		}
	}
	return Min_len;
}
int main_13()
{
	char str[10];
	char src[100];
	int n;
	int result;
	cin >> str;
	cin >> src;
	int length1 = strlen(str);
	int length2 = strlen(src);
	result = getMin_str(str, length1, src, length2);
	cout << result << endl;
	return 0;

}