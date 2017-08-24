#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) { }
};
/*
碰到seperator中字符，则自动分割
*/
vector<string> split(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//找到字符串中首个不等于分隔符的字母；
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {
					++i;
					flag = 0;
					break;
				}
		}
		//找到又一个分隔符，将两个分隔符之间的字符串取出；
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}

long hex2int(const string& hexStr)
{
	char *offset;
	if (hexStr.length() > 2)
	{
		if (hexStr[0] == '0' && hexStr[1] == 'x')
		{
			return strtol(hexStr.c_str(), &offset, 0);
		}
	}
	return strtol(hexStr.c_str(), &offset, 16);
}
ListNode* Meet_Node(ListNode* pHead) {
	ListNode* result = NULL;
	ListNode* pslow = pHead;
	ListNode* pfast = pHead;
	while (pslow != NULL && pfast != NULL) {
		pslow = pslow->next;
		pfast = pfast->next;//一次跑两步
		if (pfast != NULL) {
			pfast = pfast->next;
		}
		if (pslow == pfast)//如果存在环，仅可有此处跳出
		{
			result = pslow;
			break;
		}

	}
	return result;
}
void AddDependency(unsigned int Moduleld,unsigned int DependModuleld) {
	cout << Moduleld << " " << DependModuleld << endl;

}
bool MouldelsCycularDependency(unsigned int Moduleld) {
	return false;
}
void clear() {

}
int main_h() {
	string str,str1="";
	vector<string> v_str;
	cout << "please cin a line:" << endl;;
	while (cin >> str) {
		v_str.push_back(str);
	}
	vector<vector<string>> temp;
	vector<string> v;
	for (int i = 0; i < v_str.size(); ++i) {
		 v = split(v_str[i], "{,}");
		 temp.push_back(v);
	}
	for (int i = 0; i < temp.size(); ++i)
	{
		int num1 = hex2int(temp[i][0]);
		int num2 = hex2int(temp[i][1]);
		AddDependency(num1,num2);
	}
	return 0;
}