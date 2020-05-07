#include "pch.h"
#include<iostream>
#include<vector>
using namespace std;


/*
 * 一个区分左值与右值的便捷方法是：看能不能对表达式取地址，如果能，则为左值，否则为右值

	非常量左值引用只能绑定到非常量左值，不能绑定到常量左值、非常量右值和常量右值。
	如果允许绑定到非常量右值，则会导致非常危险的情况出现，因为非常量右值是一个临时对象，非常量左值引用可能会使用一个已经被销毁了的临时对象。
	常量左值引用可以绑定到所有类型的值，包括非常量左值、常量左值、非常量右值和常量右值。
   
*/


const char* s[9] = { "C++","java","python","golang" ,"unity3D","erlang","PHP","JSP","java scrip"};
int index = 0;
class A {
public:
	A() {
		cout << "A的构造函数" << endl;
		str = new char[20];
	//	str = s[index++];
		str = "hello";
	}
	~A() {
		cout << "A的析构函数" << endl;
		delete str;
	}
	//常量引用的初始值可以是任意类型   
	A(const A& a) {
		cout << "A的拷贝构造函数" << endl;
	}
	A& operator=(const A& a) {
		cout << "重载赋值运算符" << endl;
		//不用自我赋值
		if (this != &a) {
			if (str != NULL) {
				delete str;
				str = NULL;
			}
			str = new char[15];
			str = s[index++];
		
		}
		return *this;
	}
public:
	 const char *str;
};


void test01() {
	int a = 10;
	int b = 20;
	int* pFlag = &a;
	string str1 = "hello ";
	string str2 = "world";
	const int &m = 1;
	//&(a + b);		错
	&(++a);
	//&(a++);		错
	&(string("sa"));
	&pFlag;
	&(str1 + str2);
	&("hello");
	//int& i = 2;	非常量引用的初始值必须为左值
	const int& j = 2;
}
void test02() {
	A a;			//析构出错？？
	//A a2(a);				//析构a2时为什么会出错？？？？？？
	//A a3 = a;				//这是初始化  不调用重载赋值运算符  调用的拷贝
	//a2.operator=(a);		//这是赋值  不是初始化  不会调用拷贝构造函数
	//A* p1 = new A;
	//A* p2 = new A();
	//A* p3 = p2;
}
class B {
public:
	B(){}
	B(int a){}
	void show() {
		cout << "hello world" << endl;
	}

};
int main()
{
	B b;
	//b.show();
	//test01();
	//test02();
}
