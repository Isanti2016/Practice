//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
///*
//针对非大数的m进制转n进制
//输入
//16 10    //m=16,n=10
//F		 //m进制的数
//输出
//15		//n进制的数
//*/
//int main()
//{
//	int m, n;
//	string str;
//	cin >> m;
//	cin >> n;
//	cin >> str;
//	vector<char> hashs;
//	for (int i = 0; i < m;++i)
//	{
//		char temp;
//		if (i<=9)
//			temp = i + '0';
//		else
//			temp = (i-10) + 'a';
//		hashs.push_back(temp);
//	}
//
//	int num=0;
//	for (int i = 0; i < str.size();++i)
//	{
//		if (str[i]>='0' && str[i]<='9')
//		{ 
//			int temp;
//			temp = str[i] - '0';
//			num = num * m + temp;
//		}
//		if (str[i]>='A'&&str[i]<='Z')
//		{
//			int temp;
//			temp = str[i] - 'A'+10;
//			num = num*m + temp;
//		}
//	}
//
//	string result;
//	while (num!=0)
//	{
//		char ch;
//		int Rem;
//		Rem = num%n;
//		num = num / n;
//		ch = hashs[Rem];
//		result += ch;
//	}
//
//	reverse(result.begin(),result.end());
//	cout << result << endl;
//
//	return 0;
//}


/*
针对非大数的m进制转n进制
输入
16 10    //m=16,n=10
F		 //m进制的数
输出
15		//n进制的数
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int charToDec(char ch) {
	if (ch >= '0'&&ch <= '9')
	{
		return ch - '0';
	}
	else
	{
		return ch - 'A' + 10;
	}
}
char DecTochar(int num) {
	if (num >= 0 && num <= 9)
	{
		return num + '0';
	}
	else {
		return num - 10 + 'A';
	}
}
char mod_core(string& input, int src, int dst) {
	string quotient = "";
	int temp = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		temp = temp*src + charToDec(input[i]);
		quotient += DecTochar(temp / dst);
		temp = temp%dst;
	}
	int i = 0;
	while (quotient[i] == '0')
		i++;
	input = quotient.substr(i, quotient.length() - i);
	return DecTochar(temp);
}


int main_24()
{
	int m, n;
	string str;
	string output;
	while (cin >> m >> n >> str) {
		output = "";
		while (str.length() > 0)
		{
			char mod = mod_core(str, m, n);
			output = mod + output;
		}
		for (int i = 0; i < output.length(); i++) {
			if (output[i] >= 'A' && output[i] <= 'Z')
				output[i] = 'a' + output[i] - 'A';
		}

		cout << output << endl;
	}
	return 0;
}