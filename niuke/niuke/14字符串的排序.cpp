/*
��ĸ������
*/
//#include<iostream>
//
//using namespace std;
//
//void Sort_Str(char* str, char* begin) {
//	if (*begin=='\0')
//	{
//		cout << str << " ";
//	}
//	else {
//		for (char* temp = begin; *temp != '\0'; ++temp)
//		{
//			swap(*temp, *begin);
//			Sort_Str(str, begin + 1);
//			swap(*temp, *begin);
//		}
//	}
//}
//
//int main() {
//	char str[100];
//	cin >> str;
//	Sort_Str(str, str);
//	return 0;
//}


/*
��ĸ����ϣ�Ҫ���ַ����ظ���aaaa�򲻿ɣ�abc����
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

int main_14()
{
	char s[100];
	cin >> s;
	int count = 0;
	Combination(s,count);
	cout << "��ϵĸ�����" << count << endl;
	system("pause");
	return 0;
}