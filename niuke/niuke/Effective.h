#pragma once
#include <mutex>
#include <vector>

using namespace std;
class widgetsImpl {
public:
private:
	int a, b, c;
	vector<double> v;
};

class Widgets {
public:
	Widgets& operator[](std::size_t position);//返回值应该是引用&，方便修改值
	Widgets& operator=(const Widgets& rhs)//处理自我赋值和异常的三种方法
	{
		//if (this==&rhs)
		//{
		//	return *this;
		//}
		//delete str;
		//str = new char(*(rhs.str));//new的时候失败会导致异常
		//return *this;

		//char* Orig = str;
		//str = new char(*rhs.str);
		//delete Orig;//也是异常安全，当new失败是不会删除Orig
		//return *this;

		Widgets temp(rhs);
		swap(temp);//利用Copy and Swap技术
		return *this;
	};
	//void swap(Widgets& rhs) {//用于异常安全的swap
	//	using std::swap;
	//	swap(*this, rhs);
	//}

	void swap(Widgets& rhs) {//用于高效率的swap，使用impl手法
		using std::swap;
		swap(Impl,rhs.Impl);
	}
private:
	static const int Numbers = 5;//类中的const变量，为了确保常量Numbers只有一个实体必须定义为static,此种情况可以直接在类中初始化(仅对于int类型)
	//static const double FudgeFactor=5;//非int类型不能初始化
	enum{Numbers_1=5};					//可以
	int scores[Numbers_1];				//the enum hack补偿法，用于定义数组
	static const double FudgeFactor;

	char* str;
	widgetsImpl* Impl;
};
const double Widgets::FudgeFactor = 1.35;//正常static的初始化，一般在.cpp中

const Widgets operator*(const Widgets& lhs, const Widgets& rhs);//*操作符返回值为const，是防止对乘积结果赋值，如果所有参数需要类型转换，则采用non-number函数

namespace std {//特化std内部的swap，用于Widgets版本的swap调用,和class中swap连用，主要是为了高效使用std内部的swap
	template<>
	void swap<Widgets>(Widgets& lhs, Widgets& rhs) {
		lhs.swap(rhs);
	}
}

/*
空类中存在的函数
*/
class Empty {
public:
	Empty() {  };
	Empty(const Empty& rhs) {};
	~Empty() { };
	Empty& operator=(const Empty& rhs)//仅有一个参数，并返回*this
	{
		return *this;
	};
private:
	const Widgets operator*(const Widgets& lhs) {//仅有一个参数，并返回const Widgets 只能值传递

	}
};
/*
明确声明不让编译器自动生成函数
*/
class HomeForSale {
public:
private:
	HomeForSale(const HomeForSale&);//仅仅声明，阻止编译器生成默认函数，但是这个只是在连接期才提示错误，可以用Uncopyable基类
	HomeForSale& operator=(const HomeForSale&);
};

/*
自己设计的资源管理类，互斥对象
*/
void lock_p(mutex *pm);
void unlock_p(mutex *pm);

class Lock{
public:
	explicit Lock(mutex* pm):mutexPtr(pm) {
		lock_p(mutexPtr);
	}
	~Lock() {
		unlock_p(mutexPtr);
	}
	mutex* get()const { return mutexPtr; }//显示的方法，用于获得内部资源mutex*
	operator mutex*() const { return mutexPtr; }//隐式的方法，用于获得内部资源mutex*
private:
	mutex* mutexPtr;
	Lock(const Lock&);//禁止复制
	Lock& operator=(const Lock&);
};

class Lock_count {
public:
	explicit Lock_count(mutex* pm):mutexPtr(pm,unlock_p) {
		lock_p(mutexPtr.get());
	}
	//无析构函数
private:
	std::tr1::shared_ptr<mutex> mutexPtr;//对复制行为使用计数法
};

namespace WidgetStuff { //命名空间WidgetStuff中
	template<typename T>//模版类定义
	class widgetsImpl_1 {
	public:
	private:
		int a, b, c;
		vector<int> vec;
	};
	template<typename T>
	class Widgets_1 {
	public:
		void swap(Widgets_1& rhs) {//类内部的swap可以高效使用
			using namespace std;
			swap(impl, rhs.impl);//核心！！！！！！高效的交换数据
		}
	private:
		widgetsImpl_1 impl;
	};
	template<typename T>//在命名空间WidgetStuff中重载的swap会首先被调用
	void swap(Widgets_1<T>& a, Widgets_1<T>& b) {
		a.swap(b);
	}
}


