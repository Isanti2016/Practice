#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
��������е�����a[i]*a[i+1]%4����0������������Ƿ���Ҫ��ģ����򣬲�����Ҫ��
����
2       //������
3       //��һ�����
1 10 100
4       //�ڶ������
1 2 3 4
���
Yes
No
*/
#include <iostream>
#include <vector>

using namespace std;

int main_30_1() {
	int t;
	cin >> t;
	while (t > 0) {
		int n;
		cin >> n;
		long long sum1 = 0, sum2 = 0, sum3 = 0;
		while (n > 0) {
			long long temp;
			cin >> temp;
			if (temp % 4 == 0)
				sum1++;
			else if (temp % 2 == 0)
				sum2++;
			else
				sum3++;
			n--;
		}
		if (sum2 == 0)
		{
			if (sum1 >= sum3 - 1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else {
			if (sum1 >= sum3)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}

/*
������������еĸ�����

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Max_CS_30(string s1, string s2) {			//�������󹫹������еĳ���
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

void STR_Sort_30(string& str, int pos,vector<string>& vec) {
	if (pos== str.size())
	{
		vec.push_back(str);
	}
	else {
		for (int i = pos; i<str.size(); ++i)
		{
			swap(str[i], str[pos]);
			STR_Sort_30(str, pos+ 1,vec);
			swap(str[i], str[pos]);
		}
	}
}
int main_30_2() {
	string str;
	cin >> str;
	vector<string> vec;
	STR_Sort_30(str,0,vec);

	for (int i = 0; i < vec.size();++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	int Max = 0,count=0;
	for (int i = 1; i < vec.size();++i)
	{
		int result = Max_CS_30(str, vec[i]);
		if (Max<result)
		{
			Max = result;
			count = 1;
		}
		else if(Max==result)
		{
			count++;
		}
	}
	cout << Max << endl;
	cout << count << endl;
	return 0;
}
