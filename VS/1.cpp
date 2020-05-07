#include "pch.h"
#include<iostream>
#include<algorithm>
#include <vector>
#include <iterator>
#include <memory>
#include<string>
using namespace std;

class A {
public:
	static int i;
public:
	A() { i++; }
	~A() {
		cout << "i = " << i << endl;
	}
};
int A::i = 0;
void print(int* p1, int n) {
	for (int i = 0; i < n; i++)
		cout << p1[i] << " ";
	cout << endl;
}
int main()
{

	A* a = new A[10];
	delete[] a;


	int *p1 = new int[10]{ 1,2,3 };
	//error: 'begin' was not declared in this scope|
	/*for(auto a : p1){
		cout << *a << endl;
	}*/
	print(p1, 10);

	//char cp[0];
	//char* cp = new char[0];       合法  但是不能解引用
	return 0;
}
