#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main_18() {
	/*��һ�ֳ������뷽����ֱ������һ������������������
	����:
	21 33 45 67
	2
	�����
	45
	*/
	//vector<int> vec;
	//char ch;
	//do
	//{
	//	int temp;
	//	scanf("%d", &temp);//charתint
	//	vec.push_back(temp);
	//} while ((ch = getchar()) != '\n');//�����س�����

	//int key;
	//cin >> key;
	
	//for (int i = 0; i < vec.size(); ++i)
	//{
	//	cout << vec[i] << " ";
	//}
	//cout << endl;
	//cout << key;
	/************************************************************************************/
	/*�ڶ������뷽��������һ��Ҫ�������ֵĸ��������������֡�
	���룺
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
	/*����һ�仰�����ո��,cin.getline()ֻ����char*�ַ�����Ҫ��new�������ַ����飬�س��Զ�����
	���룺
	wang bei bei
	*/
	//char src[100], str[100];
	//cin.getline(src, sizeof(src),'\n');
	//cin.getline(str, sizeof(str));

	//cout << src << endl;
	//cout << str << endl;
	/********************************************************************************************/
	/*����һ�仰�����ո��,��Ҫ��string,�����Զ����������߳���'\n'�Զ�����
	���룺
	wang bei bei
	*/
	//string str;
	//getline(cin,str,'\n');//string�е����ݣ�תΪstring׼��
	//cout << str << endl;
	/********************************************************************************************/
	/*��ȡһ���ַ������س���tab���ո����������Ҳ���ַ�����
	���룺
	34 25 36,
	���
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
	��������
	5   //��������������
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