/*
58 ������ҫս����
*/
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int Com_num(int num1, int num2) {
//	if (num1 == 0 || num2 == 0)
//	{
//		return -1;
//	}
//	int z = num2;
//	while (num1%num2)
//	{
//		z = num1%num2;
//		num1 = num2;
//		num2 = z;
//	}
//	return z;
//}
//int main() {
//	int x, n;
//	vector<int> vec;
//	cin >> x;
//	cin >> n;
//	while (n>0)
//	{
//		int temp;
//		cin >> temp;
//		vec.push_back(temp);
//		--n;
//	}
//	for (int i = 0; i < vec.size();++i)
//	{
//		if (vec[i]<=x)
//		{
//			x = x + Com_num(x, vec[i]);
//			
//		}
//		else {
//			x = x + vec[i];
//		}
//	}
//	cout << "x:" << x << endl;
//	return 0;
//}
/*
58 ��С�ַ����ĳ��ȣ���Ҫ������
����happywhubacc��wbau ��̵ĵ���5
*/
#include<stdio.h>  
#include<stdlib.h>  
#include<iostream>  
#include<string.h>  
#include<string>  
#include <limits.h>  
using namespace std;

int hashs[256];
int getMin_str(char str[], int length1, char src[],int length2)
{
	for (int i = 0; i < 256;++i)
	{
		hashs[i] = -1;
	}
	for (int i = 0; i < length1;++i)
	{
		hashs[str[i]] = 0;
	}
	int count = 0;
	int Min_len = 0x7fffffff;
	int i,j=0;
	for (i = 0; i < length2&&(count<length1); ++i)
	{
		if (hashs[src[i]] != -1) {
			if (hashs[src[i]] == 0)
				count++;
			hashs[src[i]]++;
		}
	}

	if (src[i]=='\0'&&(count<length1))//û�ҵ���û��ȫҪͳ�Ƶ��ַ�
	{
		return -1;
	}
	bool flag = false;
	while ((j < length2)&&(i<length2))
	{
		if (hashs[src[j]]>1)//Ҫͳ�Ƶ��ַ�����ǰ��һ���ַ��ж�������Լ�����ǰ��
		{
			hashs[src[j]]--;
			j++;
		}
		else if(hashs[src[j]]==-1) {//����Ҫͳ�Ƶ��ַ���������ǰ��
			j++;
		}
		else if (hashs[src[j]]==1)//Ҫͳ�Ƶ��ַ�����ǰ��һ���ַ�����һ��
		{
			if (hashs[src[i]]!=-1)//�ҵ�Ҫͳ�Ƶ��ַ�������ͳ��
			{
				hashs[src[i]]++;
			}
			if (src[i]==src[j])//Ҫͳ�Ƶ��ַ�����ǰ��һ���ַ��ͺ���һ���ַ���ȣ�����ͬʱ�ƶ�
			{
				j++;
				hashs[src[i]]--;
				if (i == length2 - 1) {//���һλ����Ϊǰ��Ҫ���ҵ��ַ��ǣ�Ϊ�˱���j�����任����ʱiռʱͣ��
					flag = true;
					continue;
				}

			}
			i++;//������hashs[src[j]]==1����Ϊ�ƶ�i++׼��
		}
		int temp = flag ? (i - j + 1) : i - j;//flagΪ�漴���һλ����Ϊǰ��Ҫ���ҵ��ַ�����ʱҪ��+1���㳤��
		if (Min_len > temp)//����̾���
		{
			Min_len = temp;
		}
	}
	return Min_len;
}
int main_13()
{
	char str[10];
	char src[100];
	int n;
	int result;
	cin >> str;
	cin >> src;
	int length1 = strlen(str);
	int length2 = strlen(src);
	result = getMin_str(str, length1, src, length2);
	cout << result << endl;
	return 0;

}