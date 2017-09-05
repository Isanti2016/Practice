#include<iostream>
#include <vector>
#include <string>

using namespace std;
char* Delete_Second_Char(char* src, char* str) {
	int length = strlen(src);
	char* result=new char[length];
//	char* result;
	int* hashs = new int[256];
	memset(hashs, 0, 256 * sizeof(hashs[0]));

	while(*str!='\0')
	{
		hashs[*str]++;
		str++;
	}
	int i = 0;
	while (*src!='\0')
	{
		if (hashs[*src]==0)
		{
			result[i]=*src;
			//sprintf(&result[i], "%c", *src);
			i++;
		}
		src++;
	}
	return result;
}
string Delete_Second_Str(char* src, char* str) {
	string result;
	int* hashs = new int[256];
	memset(hashs, 0, 256 * sizeof(hashs[0]));

	while (*str != '\0')
	{
		hashs[*str]++;
		str++;
	}

	while (*src != '\0')
	{
		if (hashs[*src] == 0)
		{
			result += *src;
		}
		src++;
	}
	return result;
}
int main_16() {
	char src[100], str[10];
	cin.getline(src,100);
	cin.getline(str, 100);

	char* result = Delete_Second_Char(src,str);
//	string result = Delete_Second_Str(src, str);
	cout << result << endl;;
	return 0;

}