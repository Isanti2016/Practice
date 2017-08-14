#include <iostream>
#include <string>
#include <string.h>

using namespace std;
int Max_od(string str) {
	int length = str.size();
	int str_len = length - 2;
	int result = 2;
	for (int i = 0, j = str_len / 2; i < str_len / 2;) {
		if (str[i] == str[j]) {
			i++;
			j++;
		}
		else {
			str_len -= 2;
			i = 0;
			j = str_len/ 2;
			result += 2;
		}
	}
	return length - result;
}
int main_3(){
	string str;
	cin >> str;
	int max_length = Max_od(str);
	cout << max_length << endl;
	return 0;
}
