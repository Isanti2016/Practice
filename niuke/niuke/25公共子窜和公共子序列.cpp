/*
�Ӵ�������������abc�е��Ӵ� ����a b c ab bc abc
�����ַ����Ĺ����Ӵܸ����ͣ���Ĺ����Ӵ�
����:
abc
ab
�����
3 2   //3�������Ӵܵĸ�����2��Ĺ����Ӵ�
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int Max_CH_25(string longstr,string shortstr,set<string>& result) {     //������Ӵܵĳ���return ,�����Ӵ���result�в���ȥ���ظ�
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
	set<string> set_str;//������й����Ӵܣ����ظ����ų�
	set_str.clear();

	int result=Max_CH_25(longstr, shortstr, set_str);

	cout << set_str.size() << " " << result << endl;
	return 0;
}

/*
�����У��ǲ��ı����е�˳�򣬶���������ȥ�������Ԫ�ض�����µ�����,��������������в�ֹһ��
�����ַ����Ĺ����Ӵܸ����ͣ���Ĺ����Ӵ�
���� :
13456778
357486782
�����
����������еĳ��ȣ�5
������������ǣ�34678     //����������Ҳ���ܱ���35778
*/
int Max_Sequence_25(string s1, string s2) {			//�������󹫹������еĳ���
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
			if (s1[i - 1] == s2[j - 1])//-1����Ϊ�ַ�����0��ʼ����countȴҪ��1��ʼ����count[0][i],count[j][0]�������Ϊ0��
				count[i][j] = count[i - 1][j - 1] + 1;
			else {
				count[i][j] = max(count[i - 1][j], count[i][j - 1]);
			}
		}
	}
	return count[length1][length2];
}
int Max_Sequence_25(string s1, string s2, int**flag) {			//����������еĳ���return��flag��־��������result��
	int length1 = s1.size();
	int length2 = s2.size();

	int n1 = length1 + 1, n2 = length2 + 1;//ע�����������+1֮��ĵ�һ�к͵�һ�ж�Ϊ0
	int** count = new int*[n1];
	for (int i = 0; i < n1; i++)
	{
		count[i] = new int[n2];
		memset(count[i], 0, n2*sizeof(int));//����new������ڴ���ܲ����������ͳһ����ֵ��ʱ������⣬memset�����ֽ�Ϊ��λ���и�ֵ��
	}
	//for (int i = 0; i < n1;i++)
	//{
	//	for (int j = 0; j < n2;j++)
	//	{
	//		count[i][j]=0;
	//	}
	//}

	for (int i = 1; i <= length1; ++i) //����i��j���Դ�1��ʼ����count[][]��ֵ
	{
		for (int j = 1; j <= length2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])//�˴���s1�ַ���
			{
				int temp = count[i - 1][j - 1];
				count[i][j] = count[i - 1][j - 1] + 1;
				flag[i][j] = 1;  ///б���±��
			}
			else if (count[i][j - 1]>count[i - 1][j])//�˴���count����
			{
				count[i][j] = count[i][j - 1];
				flag[i][j] = 2;  //���ұ��
			}
			else
			{
				count[i][j] = count[i - 1][j];
				flag[i][j] = 3;  ///���±��
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
		if (flag[i][j]==1)   //б���±��
		{
			result = s1[i-1] + result;
			i--;
			j--;
		}
		else if (flag[i][j] == 2) { //���ұ��
			j--;
		}
		else if(flag[i][j]==3)//���±��
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
		memset(flag[i], 0, (length2 + 1)*sizeof(int));//����new������ڴ���ܲ����������ͳһ����ֵ��ʱ������⣬memset�����ֽ�Ϊ��λ���и�ֵ��
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


	cout << "����������еĳ��ȣ�" << Max_CH << endl;
	cout << "������������ǣ�" << Comm_str << endl;
	return 0;
}