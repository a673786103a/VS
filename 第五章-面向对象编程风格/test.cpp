#include "test.h"
#include "Fibonacci.h"
#include "Triangular.h"
#include <typeinfo>
#define CLS cout << "**********************************************" << endl;

test::test()
{
}


test::~test()
{
}

void test::test01() {
	//LibMat lm;
	//print(lm);
	//Book book("C++ Primer", "stven");
	//print(book);
	AudioBook ab("Tom", "C++", "java");
	print(ab);
}
void test::test02() {
	Fibonacci fib(12,3);
	cout << "(3,12)beginning at 3 with the length of 12 - fib :  " << fib << endl;
	CLS
	Fibonacci fib2(10);
	cout << "(1,10)beginning at 1 with the length of 10 - fib2 : " << fib2 << endl;
	CLS
	Fibonacci fib3(-1, 4);
	cout << "error parameters - fib3 : " << fib3 << endl;
	cout << fib3.what_am_i() << endl;
	CLS
}
//测试display
void test::test03() {
	const int pos = 5;
	Fibonacci* fib = new Fibonacci(10, 1);
	Triangular* tri = new Triangular(10, 1);
	display(cout, fib, pos);
	CLS
	display(cout, tri, pos);
	CLS
	num_sequence* n1 = new Fibonacci(10, 1);
	cout << "The real identity of n1 : " << n1->what_am_i() << endl;
	cout << "n1 begpos: " << n1->beg_pos() << endl;
	cout << "The element at 3: " << n1->elem(3) << endl;
	cout << "The length of n1: " << n1->length() << endl;
	cout << "n1: " << n1 << endl;		//这个为什么不调用重载运算符？
	CLS
	num_sequence* n2 = new Triangular(10, 1);
	cout << "The real identity of n2 : " << n2->what_am_i() << endl;
	cout << "n1 begpos: " << n2->beg_pos() << endl;
	cout << "The element at 3: " << n2->elem(3) << endl;
	cout << "The length of n2: " << n2->length() << endl;
	cout << "n2: " << n2 << endl;
	
}
//测试copy和assignment函数
void test::test04_copy_assignment() {
	Fibonacci fib(10);
	Fibonacci fib2 = fib;	//调用拷贝构造函数
	Fibonacci fib3(12);
	cout << "fib: " << fib <<endl;
	cout << "fib2: " << fib2 << endl;
	cout << "fib3: " << fib3 << endl;
	CLS
	fib3 = fib;				//调用赋值运算符重载
	cout << "fib3: " << fib3 << endl;
	cout << fib3.what_am_i() << endl;
	CLS

	Triangular tri(20);
	Triangular tri2 = tri;
	Triangular tri3(15);
	cout << "tri: " << tri << endl;
	cout << "tri2: " << tri2 << endl;
	cout << "tri3: " << tri3 << endl;
	CLS
	tri3 = tri;
	cout << "tri3: " << tri3 << endl;
	cout << tri3.what_am_i() << endl;
}

void test::test05_typeinfo_RTTI() {
	//测试typeid  - 返回一个type_info对象
	num_sequence* n1 = new Fibonacci;
	cout << typeid(n1).name() << endl;	//class num_sequence * __ptr64
	cout << typeid(*n1).name() << endl;	//class Fibonacci
	CLS
	Triangular tri;
	n1 = &tri;
	cout << typeid(n1).name() << endl;	//class num_sequence * __ptr64
	cout << typeid(*n1).name() << endl;	//class Triangular
	CLS
	//OK  n1确实指向某个Triangular对象  
	if (typeid(*n1) == typeid(Triangular)) {
		cout << "n1 pointer to Triangular Object " << endl;
		//static_cast存在风险
		Triangular* pf = static_cast<Triangular*>(n1);
		cout << "After convert with static_cast: " << endl;
		cout << typeid(pf).name() << endl;	//class Triangular * __ptr64
		cout << typeid(*pf).name() << endl;	//class Triangular
		cout << "pf: " << pf << endl;		//不会调用重载函数，打印出pf指针变量的值
	}
	CLS
	if (Fibonacci* tri2 = dynamic_cast<Fibonacci*>(n1)) {
		cout << "yes" << endl;
	}
	
}