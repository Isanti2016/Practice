#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
����һ������n���������1��n���ֵ�����У�ʵ�ʾ��Ƕ��ַ�����������ʹ��strcmp����
����
15
���
1 10 11 12 13 14 15 2 3 4 5 6 7 8 9
*/
int main()
{
		int n;
		int i, j;
		char a[1000][1000];
		char t[1000];
		int k = 0;
		cin>>n;
		for (i = 1; i <= n; i++)
		{
			_itoa(i, a[k], 10);  //������ת��Ϊ�ַ������뵽�ַ�������a��,10����10����!!!!!!!!!!a[i]���÷�
			k++;
		}
		for (i = 0; i < k - 1; i++)				//���ַ�������
		{
			for (j = k-1; j>0; j--)				//ʵ�����ַ�����ð������
			{
				if (strcmp(a[j], a[j - 1]) < 0)
				{
					swap(a[j],a[j-1]);//����Сֵ��������
					//strcpy(t, a[j]);
					//strcpy(a[j], a[j + 1]);
					//strcpy(a[j + 1], t);

				}
			}
		}
		for (i = 0; i < k; i++)//����������ַ���
			cout<<a[i]<<" ";
		cout << endl;


		return 0;
}