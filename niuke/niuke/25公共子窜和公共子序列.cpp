/*
子窜是连续的例如abc中的子窜 ，有a b c ab bc abc
两个字符串的公共子窜个数和，最长的公共子窜
输入:
abc
ab
输出：
3 2   //3代表公共子窜的个数，2最长的公共子窜
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int Max_CH_25(string longstr,string shortstr,set<string>& result) {     //最长公共子窜的长度return ,公共子窜在result中并且去除重复
	int dif = -1;
	for (int i = 0; i < shortstr.size(); ++i)
	{
		for (int j = 1; j <= shortstr.size(); ++j)
		{
			string temp = shortstr.substr(i, j);
			int val = longstr.find(temp);
			if (val != -1)
			{
				result.insert(temp);
				int num = temp.size();
				if (dif < num)
				{
					dif = num;
				}
			}

		}
	}
	return dif;
}

int main_25() {
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	string longstr=str1;
	string shortstr=str2;
	if (str1.size()<str2.size())
	{
		longstr = str2;
		shortstr = str1;
	}
	set<string> set_str;//存放所有公共子窜，把重复的排除
	set_str.clear();

	int result=Max_CH_25(longstr, shortstr, set_str);

	cout << set_str.size() << " " << result << endl;
	return 0;
}

/*
子序列：是不改变序列的顺序，而从序列中去掉任意的元素而获得新的序列,并且最长公共子序列不止一个
两个字符串的公共子窜个数和，最长的公共子窜
输入 :
13456778
357486782
输出：
最长公共子序列的长度：5
最长公共子序列是：34678     //或者其他的也可能比如35778
*/
int Max_Sequence_25(string s1, string s2) {			//可求出最大公共子序列的长度
	int length1 = s1.size();
	int length2 = s2.size();

	int n1 = length1 + 1, n2 = length2 + 1;
	int** count = new int*[n1];
	for (int i = 0; i < n1; i++)
		count[i] = new int[n2];

	for (int i = 0; i < length1; ++i) {
		count[i][0] = 0;
	}
	for (int i = 0; i < length2; ++i) {
		count[0][i] = 0;
	}
	for (int i = 1; i <= length1; ++i)
	{
		for (int j = 1; j <= length2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])//-1是因为字符串从0开始，而count却要重1开始计算count[0][i],count[j][0]都被填充为0了
				count[i][j] = count[i - 1][j - 1] + 1;
			else {
				count[i][j] = max(count[i - 1][j], count[i][j - 1]);
			}
		}
	}
	return count[length1][length2];
}
int Max_Sequence_25(string s1, string s2, int**flag) {			//最长公共子序列的长度return，flag标志的数组在result中
	int length1 = s1.size();
	int length2 = s2.size();

	int n1 = length1 + 1, n2 = length2 + 1;//注意这个长度是+1之后的第一行和第一列都为0
	int** count = new int*[n1];
	for (int i = 0; i < n1; i++)
	{
		count[i] = new int[n2];
		memset(count[i], 0, n2*sizeof(int));//两次new分配的内存可能不连续，造成统一赋初值的时候出问题，memset是以字节为单位进行赋值的
	}
	//for (int i = 0; i < n1;i++)
	//{
	//	for (int j = 0; j < n2;j++)
	//	{
	//		count[i][j]=0;
	//	}
	//}

	for (int i = 1; i <= length1; ++i) //所以i和j可以从1开始计算count[][]的值
	{
		for (int j = 1; j <= length2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])//此处是s1字符串
			{
				int temp = count[i - 1][j - 1];
				count[i][j] = count[i - 1][j - 1] + 1;
				flag[i][j] = 1;  ///斜向下标记
			}
			else if (count[i][j - 1]>count[i - 1][j])//此处是count数组
			{
				count[i][j] = count[i][j - 1];
				flag[i][j] = 2;  //向右标记
			}
			else
			{
				count[i][j] = count[i - 1][j];
				flag[i][j] = 3;  ///向下标记
			}
		}
	}
	return count[length1][length2];
}
string getLCS_25(string s1,string s2,int **flag) {
	string result;
	int i = s1.size();
	int j = s2.size();
	while (i>0 && j>0)
	{	
		if (flag[i][j]==1)   //斜向下标记
		{
			result = s1[i-1] + result;
			i--;
			j--;
		}
		else if (flag[i][j] == 2) { //向右标记
			j--;
		}
		else if(flag[i][j]==3)//向下标记
		{
			i--;
		}
	}
	return result;
}
int main_Seq_25() {
	string str1, str2;
	cin >> str1;
	cin >> str2;

	int length1 = str1.size();
	int length2 = str2.size();

	int **flag = new int*[length1+1];
	for (int i = 0; i < length1+1;++i)
	{
		flag[i] = new int[length2+1];
		memset(flag[i], 0, (length2 + 1)*sizeof(int));//两次new分配的内存可能不连续，造成统一赋初值的时候出问题，memset是以字节为单位进行赋值的
	}

	//for (int i = 0; i < length1+1;i++)
	//{
	//	for (int j = 0; j < length2+1;j++)
	//	{
	//		flag[i][j]=0;
	//	}
	//}
	int Max_CH = Max_Sequence_25(str1, str2,flag);

	string Comm_str = getLCS_25(str1,str2,flag);


	cout << "最长公共子序列的长度：" << Max_CH << endl;
	cout << "最长公共子序列是：" << Comm_str << endl;
	return 0;
}