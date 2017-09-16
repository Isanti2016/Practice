#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
输入一个整数n，输出数字1到n按字典的序列，实质就是对字符串进行排序使用strcmp即可
输入
15
输出
1 10 11 12 13 14 15 2 3 4 5 6 7 8 9
*/
int main()
{
		int n;
		int i, j;
		char a[1000][1000];
		char t[1000];
		int k = 0;
		cin>>n;
		for (i = 1; i <= n; i++)
		{
			_itoa(i, a[k], 10);  //将数字转换为字符串存入到字符串数组a中,10代表10进制!!!!!!!!!!a[i]的用法
			k++;
		}
		for (i = 0; i < k - 1; i++)				//将字符串排序
		{
			for (j = k-1; j>0; j--)				//实质是字符串的冒泡排序
			{
				if (strcmp(a[j], a[j - 1]) < 0)
				{
					swap(a[j],a[j-1]);//把最小值带到顶部
					//strcpy(t, a[j]);
					//strcpy(a[j], a[j + 1]);
					//strcpy(a[j + 1], t);

				}
			}
		}
		for (i = 0; i < k; i++)//输出排序后的字符串
			cout<<a[i]<<" ";
		cout << endl;


		return 0;
}