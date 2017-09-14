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

CMyString::CMyString(const char* pData)//默认构造函数
{
	if (NULL == pData)//为空时，分配一个字节的空间
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

CMyString::CMyString(const CMyString& other)//拷贝构造，用于创建对象并赋值，值传递
{
	m_pData = new char[strlen(other.m_pData) + 1];
	strcpy(m_pData, other.m_pData);
}

CMyString::~CMyString()//析构函数
{
	delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)//赋值运算符重载
{
	if (this != &str)
	{
		CMyString str_temp(str);//创建临时变量，防止内存分配失败。保留原来值，是强烈保证

		//char* str = str_temp.m_pData;//第一种，写完整个过程，完成交换的功能
		//str_temp.m_pData = m_pData;
		//m_pData = str;
		swap(*this, str_temp);//第二种，copy_swap技术
	}
	return *this;
}