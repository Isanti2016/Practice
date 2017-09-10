/*
�������Ĺ��������У���ĸ����˳��ġ�
�Ӵܣ��ַ������������ַ�������ɾ��
�����У��ǴӲ��ı����е�˳�򣬶���������ȥ�������Ԫ�ض�����µ�����
����������ַ���ɾ��һЩ�ַ���ʣ�µ��ǻ��Ĵܣ�ʵ�����ַ����͵����ַ�������󹫹�������
����
abcda  //ɾ������b��d
google
���
2
2
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int Max_CS_5(string s1, string s2) {			//�������󹫹������еĳ���
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
int main_5() {
	vector<string> str;
	string temp;
	while (cin >> temp) {
		str.push_back(temp);
	}
	vector<int> result;
	for (int i = 0; i < str.size(); ++i) {
		string s1 = str[i];
		reverse(s1.begin(), s1.end());
		int delete_count = str[i].size()-Max_CS_5(str[i], s1);
		result.push_back(delete_count);
	}
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
	return 0;
}