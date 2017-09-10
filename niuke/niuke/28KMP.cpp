#include <iostream>
#include <vector>
#include <string>

using namespace std;
void Get_Next(string str2, vector<int> next) {

}
int Index_KMP(string str1, string str2,vector<int> next,int pos) {
	int result = -1;


	return result;
}
int main_28() {
	string str1, str2;
	cin >> str1 >> str2;
	vector<int> next;
	int pos = 0;
	Get_Next(str2, next);
	int result = Index_KMP(str1,str2,next,pos);

	if (result==-1)
	{
		cout << "No Find" << endl;
	}
	else {
		cout <<"Position:"<<result << endl;
	}
	return 0;
}