#include "test.h"
#include "Fibonacci.h"
#include "Triangular.h"

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
	Fibonacci fib2(10);
	cout << "(1,10)beginning at 1 with the length of 10 - fib2 : " << fib2 << endl;
	Fibonacci fib3(-1, 4);
	cout << "error parameters - fib3 : " << fib3 << endl;

	cout << fib3.what_am_i() << endl;
}
void test::test03() {
	const int pos = 5;
	Fibonacci* fib = new Fibonacci(10, 1);
	Triangular* tri = new Triangular(10, 1);
	display(cout, fib, pos);
	display(cout, tri, pos);
}