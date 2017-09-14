#pragma once
#include <iostream>

using namespace std;

class CMyString
{
public:
	CMyString(const char* pData = NULL);
	CMyString(const CMyString &other);
	~CMyString();
	CMyString& CMyString::operator =(const CMyString &str);
private:
	char* m_pData;
};

CMyString::CMyString(const char* pData)//Ĭ�Ϲ��캯��
{
	if (NULL == pData)//Ϊ��ʱ������һ���ֽڵĿռ�
	{
		m_pData = new char[1];
		*m_pData = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& other)//�������죬���ڴ������󲢸�ֵ��ֵ����
{
	m_pData = new char[strlen(other.m_pData) + 1];
	strcpy(m_pData, other.m_pData);
}

CMyString::~CMyString()//��������
{
	delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)//��ֵ���������
{
	if (this != &str)
	{
		CMyString str_temp(str);//������ʱ��������ֹ�ڴ����ʧ�ܡ�����ԭ��ֵ����ǿ�ұ�֤

		//char* str = str_temp.m_pData;//��һ�֣�д���������̣���ɽ����Ĺ���
		//str_temp.m_pData = m_pData;
		//m_pData = str;
		swap(*this, str_temp);//�ڶ��֣�copy_swap����
	}
	return *this;
}