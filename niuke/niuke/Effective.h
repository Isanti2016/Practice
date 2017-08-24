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
	Widgets& operator[](std::size_t position);//����ֵӦ��������&�������޸�ֵ
	Widgets& operator=(const Widgets& rhs)//�������Ҹ�ֵ���쳣�����ַ���
	{
		//if (this==&rhs)
		//{
		//	return *this;
		//}
		//delete str;
		//str = new char(*(rhs.str));//new��ʱ��ʧ�ܻᵼ���쳣
		//return *this;

		//char* Orig = str;
		//str = new char(*rhs.str);
		//delete Orig;//Ҳ���쳣��ȫ����newʧ���ǲ���ɾ��Orig
		//return *this;

		Widgets temp(rhs);
		swap(temp);//����Copy and Swap����
		return *this;
	};
	//void swap(Widgets& rhs) {//�����쳣��ȫ��swap
	//	using std::swap;
	//	swap(*this, rhs);
	//}

	void swap(Widgets& rhs) {//���ڸ�Ч�ʵ�swap��ʹ��impl�ַ�
		using std::swap;
		swap(Impl,rhs.Impl);
	}
private:
	static const int Numbers = 5;//���е�const������Ϊ��ȷ������Numbersֻ��һ��ʵ����붨��Ϊstatic,�����������ֱ�������г�ʼ��(������int����)
	//static const double FudgeFactor=5;//��int���Ͳ��ܳ�ʼ��
	enum{Numbers_1=5};					//����
	int scores[Numbers_1];				//the enum hack�����������ڶ�������
	static const double FudgeFactor;

	char* str;
	widgetsImpl* Impl;
};
const double Widgets::FudgeFactor = 1.35;//����static�ĳ�ʼ����һ����.cpp��

const Widgets operator*(const Widgets& lhs, const Widgets& rhs);//*����������ֵΪconst���Ƿ�ֹ�Գ˻������ֵ��������в�����Ҫ����ת���������non-number����

namespace std {//�ػ�std�ڲ���swap������Widgets�汾��swap����,��class��swap���ã���Ҫ��Ϊ�˸�Чʹ��std�ڲ���swap
	template<>
	void swap<Widgets>(Widgets& lhs, Widgets& rhs) {
		lhs.swap(rhs);
	}
}

/*
�����д��ڵĺ���
*/
class Empty {
public:
	Empty() {  };
	Empty(const Empty& rhs) {};
	~Empty() { };
	Empty& operator=(const Empty& rhs)//����һ��������������*this
	{
		return *this;
	};
private:
	const Widgets operator*(const Widgets& lhs) {//����һ��������������const Widgets ֻ��ֵ����

	}
};
/*
��ȷ�������ñ������Զ����ɺ���
*/
class HomeForSale {
public:
private:
	HomeForSale(const HomeForSale&);//������������ֹ����������Ĭ�Ϻ������������ֻ���������ڲ���ʾ���󣬿�����Uncopyable����
	HomeForSale& operator=(const HomeForSale&);
};

/*
�Լ���Ƶ���Դ�����࣬�������
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
	mutex* get()const { return mutexPtr; }//��ʾ�ķ��������ڻ���ڲ���Դmutex*
	operator mutex*() const { return mutexPtr; }//��ʽ�ķ��������ڻ���ڲ���Դmutex*
private:
	mutex* mutexPtr;
	Lock(const Lock&);//��ֹ����
	Lock& operator=(const Lock&);
};

class Lock_count {
public:
	explicit Lock_count(mutex* pm):mutexPtr(pm,unlock_p) {
		lock_p(mutexPtr.get());
	}
	//����������
private:
	std::tr1::shared_ptr<mutex> mutexPtr;//�Ը�����Ϊʹ�ü�����
};

namespace WidgetStuff { //�����ռ�WidgetStuff��
	template<typename T>//ģ���ඨ��
	class widgetsImpl_1 {
	public:
	private:
		int a, b, c;
		vector<int> vec;
	};
	template<typename T>
	class Widgets_1 {
	public:
		void swap(Widgets_1& rhs) {//���ڲ���swap���Ը�Чʹ��
			using namespace std;
			swap(impl, rhs.impl);//���ģ�������������Ч�Ľ�������
		}
	private:
		widgetsImpl_1 impl;
	};
	template<typename T>//�������ռ�WidgetStuff�����ص�swap�����ȱ�����
	void swap(Widgets_1<T>& a, Widgets_1<T>& b) {
		a.swap(b);
	}
}


