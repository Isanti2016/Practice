#include <iostream>
#include <mutex>
using namespace std;
//����ģʽ
class Singleton
{
public:	
	static Singleton* Getinstance();
private:
	Singleton() {}
	static Singleton* instance;//��Ҫ��ʼ��
	static mutex mtx;
};
Singleton* Singleton::instance = NULL;
mutex Singleton::mtx;//��ʼ��

Singleton* Singleton::Getinstance()//������ʱ���ų�ʼ��
{
	if (instance == NULL)
	{
		mtx.lock();
		if (instance == NULL)
		{
			instance = new Singleton;
		}
		mtx.unlock();
	}
	return instance;
}

//����ģʽ
class Singleton1
{
public:
	static Singleton1* Getinstance();
private:
	Singleton1() {}
	static Singleton1* instance;
};
Singleton1* Singleton1::instance = new Singleton1;//����������ʱ��ͳ�ʼ��

Singleton1* Singleton1::Getinstance()
{
	return instance;
}

int main_2() {
	return 0;
}