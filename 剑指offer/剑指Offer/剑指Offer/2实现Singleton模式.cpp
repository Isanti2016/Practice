#include <iostream>
#include <mutex>
using namespace std;
//懒汉模式
class Singleton
{
public:	
	static Singleton* Getinstance();
private:
	Singleton() {}
	static Singleton* instance;//需要初始化
	static mutex mtx;
};
Singleton* Singleton::instance = NULL;
mutex Singleton::mtx;//初始化

Singleton* Singleton::Getinstance()//调用它时，才初始化
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

//饿汉模式
class Singleton1
{
public:
	static Singleton1* Getinstance();
private:
	Singleton1() {}
	static Singleton1* instance;
};
Singleton1* Singleton1::instance = new Singleton1;//声明这个类的时候就初始化

Singleton1* Singleton1::Getinstance()
{
	return instance;
}

int main_2() {
	return 0;
}