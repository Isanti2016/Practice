#include <iostream>
#include <string>

using namespace std;
int main_1()
{
	string str;
	cin >> str;
	int length = str.size();
	int i = 0,j = 1;
	int max = 0,count=0;
	bool flag = true;
 	while (j < length-1)
	{
		if (str[i]==str[j])
		{
			flag = false;
			count++;
			i++;
			j++;
			if (count>max && i==j-count)
			{
				max = count;
			}

		}
		else
		{
			if (flag)
			{
				j++;
				flag = true;
			}
			else
			{
				flag = true;
				j = j - count+1;
				count = 0;				
				i = 0;//清空重新计数
			}
		}
	}
	cout <<  2*max << endl;
	return 0;
}
