#include "test.h"
#include "Fibonacci.h"
#include "Triangular.h"
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
	Fibonacci fib2 = fib;
	Fibonacci fib3(12);
	cout << "fib: " << fib <<endl;
	cout << "fib2: " << fib2 << endl;
	cout << "fib3: " << fib3 << endl;
	CLS
//	fib3 = fib;
//	cout << "fib3: " << fib3 << endl;
}