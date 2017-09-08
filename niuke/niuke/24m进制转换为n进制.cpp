//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
///*
//��ԷǴ�����m����תn����
//����
//16 10    //m=16,n=10
//F		 //m���Ƶ���
//���
//15		//n���Ƶ���
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
��ԷǴ�����m����תn���ƣ�����Ϊ��д�����ΪСд����2<=m,n<<36;
����
16 10    //m=16,n=10
F		 //m���Ƶ���
���
15		//n���Ƶ���
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
�Դ����Ľ���ת�������Բ��ô����ĳ������㡣
����Ҫ��һ����������1011��ת����һ������������
1���ö��������ĵ�һλ1ȥ����3����Ϊ0��������1
2������ǰ��һλ�ĳ������������������Ҫ������*(����)+��Ϊ���֡����ڱ���������1(����)*2(����)+0(��ǰ��λ����ֵ)=2������3����0��������2
3��ͬ2������2(����)*2(����)+1(��ǰ��λ����ֵ)=5��5����3����1������2
4��ͬ2������2(����)*2(����)+1(��ǰ��λ����ֵ)=5��5����3����1������2
�����Ĳ����Ա�ʾΪ 1011(2-based) / 3(Ҫת���ɵĻ���) = 0011(2-based ��).. 2(3-based ����)
Ȼ������0011����3���ظ����ϲ��裬ֱ����Ϊ0��ÿ�ε����������������3Ϊ��������

1011/3 -->0011 ..2
0011/3 -->0001 ..0
0001/3 -->0000 ..1
���ԣ�1011(2-based) --> 102(3-based)

M����תN����:����Ϊ��Сд�����Ϊ��Сд������ת����index����Ϊ����
���룺
16 8
FDCC25
�����
8���ƵĽ����77346045
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
				Quotient = Quotient + index[rem / dst];//Quotient�д�ŵ�����
				rem = rem%dst;					//rem�д�ŵ�������
			}

		}
		result = index[rem] + result;		//rem�д����������ת��Ϊ��Ӧ��dst����,ע��+��������˳��
		for (pos = 0; pos < Quotient.size() && Quotient[pos] == '0'; pos++);//����for��Ϊ��Ѱ�ҵ�һ����Ϊ'0'��λ��
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
	cout << n << "���ƵĽ����" << result << endl;
	return 0;
}