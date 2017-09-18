#include <iostream>
#include <vector>
#include <string>

using namespace std;

int x = 1;
class A {
public:
	A() { x = 3; }
	virtual ~A() { x = 5;  }
	virtual void func1() {
		x = 7;  }
	void func2() {
		x = 9;
	}
};
class B :public A {
public:
	B() {
		x = 10;
	};
	virtual ~B() {
		x = 11;
	};
	virtual void func1() {
		x = 12; 
	}
	void func2() {
		x = 13;
	}
};
B testb;
B* testc;
int main_37() {
	A* testa;
	cout << x << endl;
	testa = (A*)&testb;
	cout << x << endl;
	testa->func1();
	cout << x << endl;
	testc = new B;
	cout << x << endl;
	delete testc;
	cout << x << endl;
	testa->func2();
	cout << x << endl;
	return 0;
}
class A1{
public:
	int _a;
	A1() { _a = 1; cout << 3 << endl; }
	void print() {
		printf("%d", _a);
	}
};
class B1:public A1 {
public:
	int _a;
	B1() { _a = 2; cout << 4 << endl; }

};

int main() {
	////B1 b; 
	////b.print();
	////printf("%d", b._a);
	//int x = 5;
	//int y = 5;
	//cout << y-- << endl;
	//cout << y << endl;
	//printf("%d", x--);
	//cout << x << endl;

	return 0;
}