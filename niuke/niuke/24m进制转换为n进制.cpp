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
针对非大数的m进制转n进制，输入为大写，输出为小写，且2<=m,n<<36;
输入
16 10    //m=16,n=10
F		 //m进制的数
输出
15		//n进制的数
*/
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int charToDec(char ch) {
//	if (ch >= '0'&&ch <= '9')
//	{
//		return ch - '0';
//	}
//	else
//	{
//		return ch - 'A' + 10;
//	}
//}
//char DecTochar(int num) {
//	if (num >= 0 && num <= 9)
//	{
//		return num + '0';
//	}
//	else {
//		return num - 10 + 'A';
//	}
//}
//char mod_core(string& input, int src, int dst) {
//	string quotient = "";
//	int temp = 0;
//	for (int i = 0; i < input.size(); ++i)
//	{
//		temp = temp*src + charToDec(input[i]);
//		quotient += DecTochar(temp / dst);
//		temp = temp%dst;
//	}
//	int i = 0;
//	while (quotient[i] == '0')
//		i++;
//	input = quotient.substr(i, quotient.length() - i);
//	return DecTochar(temp);
//}
//
//
//int main_24()
//{
//	int m, n;
//	string str;
//	string output;
//	while (cin >> m >> n >> str) {
//		output = "";
//		while (str.length() > 0)
//		{
//			char mod = mod_core(str, m, n);
//			output = mod + output;
//		}
//		for (int i = 0; i < output.length(); i++) {
//			if (output[i] >= 'A' && output[i] <= 'Z')
//				output[i] = 'a' + output[i] - 'A';
//		}
//
//		cout << output << endl;
//	}
//	return 0;
//}

/*
对大数的进制转换，可以不用大数的除法运算。
假设要把一个二进制数1011，转换成一个三进制数。
1、用二进制数的第一位1去除以3，商为0，余数是1
2、由于前面一位的除法结果有余数，所以要把余数*(进制)+该为数字。对于本例，就是1(余数)*2(进制)+0(当前这位的数值)=2。除以3后，商0，余数是2
3、同2所述，2(余数)*2(进制)+1(当前这位的数值)=5。5除以3后，商1，余数2
4、同2所述，2(余数)*2(进制)+1(当前这位的数值)=5。5除以3后，商1，余数2
以上四步可以表示为 1011(2-based) / 3(要转换成的基数) = 0011(2-based 商).. 2(3-based 余数)
然后再让0011除以3，重复以上步骤，直到商为0。每次的余数的逆序就是以3为基的数。

1011/3 -->0011 ..2
0011/3 -->0001 ..0
0001/3 -->0000 ..1
所以，1011(2-based) --> 102(3-based)

M进制转N进制:输入为大小写，输出为大小写，进制转换已index数组为基础
输入：
16 8
FDCC25
输出：
8进制的结果：77346045
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int GetValue(char ch) {
	if (ch>='0'&&ch<='9'){
		return ch - '0';
	}
	else if (ch >= 'A'&&ch <= 'Z') {
		return ch - 'A' + 10;
	}
	else {
		return ch - 'a' + 36;
	}
}
string M_to_N_24(int src,int dst,string& str) {
	char index[62] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
		'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
		'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
		'y', 'z' };

	string result, Quotient;
	int rem, pos;
	while (str.size()>0)
	{
		rem = 0;
		for (pos = 0; pos < str.size();++pos)
		{
			rem = rem*src + GetValue(str[pos]);
			if (rem<dst){
				Quotient = Quotient + '0';
			}
			else {
				Quotient = Quotient + index[rem / dst];//Quotient中存放的是商
				rem = rem%dst;					//rem中存放的是余数
			}

		}
		result = index[rem] + result;		//rem中存的是余数，转换为响应的dst进制,注意+的左右有顺序
		for (pos = 0; pos < Quotient.size() && Quotient[pos] == '0'; pos++);//单独for是为了寻找第一个不为'0'的位置
		str = Quotient.substr(pos,Quotient.size());
		Quotient = "";
	}
	return result;
}

int main_24() {
	int m, n;
	cin >> m >> n;
	string str;
	cin >> str;
	string result;
	result = M_to_N_24(m,n,str);
	cout << n << "进制的结果：" << result << endl;
	return 0;
}