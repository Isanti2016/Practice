#include <iostream>
#include <vector>
#include <sstream>
#include "Common_head.h"

using namespace std;
/*
���룺
I am a student.
�����
student. a am I
*/
void Reverse(string& str, int low, int high)
{
	while (low < high)//ע�ⷴת����������Ӧ������ֵ�Ƚϡ�
	{
		swap(str[low++], str[high--]);//����ϵͳ��swap�������з�ת
	}
}

string ReverseSentence(string str) {
	string result = str;
	int length = str.size();
	if (length == 0)
		return result;
	Reverse(result, 0, length - 1);//��ת��������
	int i = 0, j = 1;//j=1��Ϊ�˷�ֹԽ��
	while (j < length)
	{
		if (j == length - 1)//��������һ�����ʻ������һ�����ʺ���û�пո����������з�ת
			Reverse(result, i, j);
		if (result[j] == ' ')//���ݿո�תÿ������
		{
			Reverse(result, i, j - 1);
			j++;
			i = j;
		}
		j++;
	}
	return result;
}
