#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main_18() {
	/*第一种场景输入方法，直接输入一行整数，在输入数字
	输入:
	21 33 45 67
	2
	输出：
	45
	*/
	//vector<int> vec;
	//char ch;
	//do
	//{
	//	int temp;
	//	scanf("%d", &temp);//char转int
	//	vec.push_back(temp);
	//} while ((ch = getchar()) != '\n');//遇到回车结束

	//int key;
	//cin >> key;
	
	//for (int i = 0; i < vec.size(); ++i)
	//{
	//	cout << vec[i] << " ";
	//}
	//cout << endl;
	//cout << key;
	/************************************************************************************/
	/*第二种输入方法，输入一个要输入数字的个数，在输入数字。
	输入：
	5
	33 25 36 54 63
	*/
	//vector<int> vec;
	//int num;
	//cin >> num;
	//while (num>0)
	//{
	//	int temp;
	//	cin >> temp;
	//	vec.push_back(temp);
	//	--num;
	//}

	//for (int i = 0; i < vec.size();++i)
	//{
	//	cout << vec[i] << "  ";
	//}
	//cout << endl;



	/*********************************************************************************************/
	/*输入一句话包括空格等,cin.getline()只能是char*字符串（要用new）或者字符数组，回车自动结束
	输入：
	wang bei bei
	*/
	//char src[100], str[100];
	//cin.getline(src, sizeof(src),'\n');
	//cin.getline(str, sizeof(str));

	//cout << src << endl;
	//cout << str << endl;
	/********************************************************************************************/
	/*输入一句话包括空格等,主要是string,换行自动结束，或者出现'\n'自动结束
	输入：
	wang bei bei
	*/
	//string str;
	//getline(cin,str,'\n');//string中的内容，转为string准备
	//cout << str << endl;
	/********************************************************************************************/
	/*读取一个字符包括回车，tab，空格，输入的数字也按字符处理
	输入：
	34 25 36,
	输出
	34 25 36
	*/
	//vector<int> vec;
	//char ch;
	//do
	//{
	//	int temp;
	//	scanf("%d", &temp);
	//	vec.push_back(temp);
	//} while ((ch = getchar()) != ',');

	//for (int i = 0; i < vec.size();++i)
	//{
	//	cout << vec[i] << " ";
	//}

	/*
	塔型输入
	5   //代表塔型行列数
	7 
	3 8 
	8 1 0
	2 7 4 4
	4 5 2 6 5
	*/
	int n;
	int a[200][200];
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				int temp;
				cin >> temp;
				a[i][j] = temp;
			}
		}
	}
	return 0;
}