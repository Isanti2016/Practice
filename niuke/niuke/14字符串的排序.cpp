/*
��ĸ��ȫ����
���룺
aab    //����ĸ�ظ�������
abc
�����
aab aba aab aba baa baa
abc acb bac bca cba cab
*/
#include<iostream>

using namespace std;

void Sort_Str(char* str, char* begin) {
	if (*begin == '\0')
	{
		cout << str << " ";
	}
	else {
		for (char* temp = begin; *temp != '\0'; ++temp)
		{
			swap(*temp, *begin);
			Sort_Str(str, begin + 1);
			swap(*temp, *begin);
		}
	}
}

int main_14_p() {
	char str[100];
	cin >> str;
	Sort_Str(str, str);
	return 0;
}

/*
vector<int> vec�����ȫ����
8�ʺ�92�ְڷŵ����⣬����ȫ���У���ȫ�������ҳ������������ģ������ܵ�ȫ������-������������
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//void Sort_num(vector<int>& vec, int num,vector<vector<int>>& result) {
//	if (num==vec.size()-1)
//	{
//		result.push_back(vec);
//	}
//	for (int i = num; i < vec.size(); ++i) {
//		swap(vec[i],vec[num]);
//		Sort_num(vec, num + 1,result);
//		swap(vec[i], vec[num]);
//	}
//}
//int main_14() {
//	//vector<int> vec = { 0,1,2,3,4,5,6,7 };//8�ʺ�
//	vector<int> vec = { 0,1,2,3};//4�ʺ�
//	vector<vector<int>> result;
//
//	Sort_num(vec,0,result);
//
//	for (int i = 0; i < result.size(); ++i) {
//		for (int j = 0; j < result[i].size(); ++j)
//		{
//			cout << result[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "�ܹ�ȫ���и�����" << result.size() << endl;
//
//	bool flag = true;
//	int count = 0;
//	for (int i = 0; i < result.size(); ++i) {
//		for (int j = 0; flag &&j < result[i].size()-1; ++j)
//		{
//			for (int k = j + 1;  k < result[i].size();++k)
//			{
//				if ((k-j==result[i][k]-result[i][j])||( k - j == result[i][j] - result[i][k]))
//				{
//					flag = false;  //������������
//				}
//			}
//		}
//		if (!flag)
//		{
//			count++;
//			flag = true;
//		}
//	}
//	cout <<"�ܹ��ʺ���԰ڷŵķ����У�"<< result.size()-count << endl;
//	return 0;
//}


/*
��ĸ����ϣ�Ҫ���ַ����ظ���aaaa�򲻿ɣ�abc���ԣ�û��setȥ��
���룺
abc
�����
a
b
c
ab
ac
bc
abc
*/
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

//��ͷɨ���ַ����õ���һ���ַ�����Ե�һ���ַ���������ѡ��
//������ַ��ŵ������ȥ��������������Ҫ��ʣ�µ�n-1���ַ���ѡȡm-1���ַ���
//�����������ַ��ŵ������ȥ������Ҫ��ʣ�µ�n-1���ַ���ѡȡm���ַ� 
void Combination(char* string, int number, vector<char>& result,int& count)
{
	if (number == 0)
	{
		++count;
		vector<char>::iterator iter = result.begin();
		for (; iter < result.end(); ++iter)
			cout << (*iter);
		cout << endl;
		return;
	}
	if (*string == '\0')
		return;
	result.push_back(*string);
	Combination(string + 1, number - 1, result,count);//������ַ��ŵ������ȥ��������������Ҫ��ʣ�µ�n-1���ַ���ѡȡm-1���ַ�
	result.pop_back();
	Combination(string + 1, number, result,count);//��������ַ��ŵ������ȥ������Ҫ��ʣ�µ�n-1���ַ���ѡȡm���ַ� 
}

void Combination(char* string,int& count)
{
	if (string == NULL)
		return;
	int length = strlen(string);
	vector<char> result;
	for (int i = 1; i <= length; i++)//i��ֵ����һ������ж��ٸ��ַ�
	{
		Combination(string, i, result,count);
	}
}

int main_14_z()
{
	char s[100];
	cin >> s;
	int count = 0;
	Combination(s,count);
	cout << "��ϵĸ�����" << count << endl;
	system("pause");
	return 0;
}