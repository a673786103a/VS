#include "LibMat.h"
#include <iostream>
using namespace std;

LibMat::LibMat()
{
	cout << "LibMat::LibMat() default constructor!\n";
}
LibMat::~LibMat()
{
	cout << "LibMat::~LibMat() deconstructor!\n";
}
void LibMat::print()const {
	cout << "LibMat::print() -- I am a LibMat object!\n";
}
void print(const LibMat& m){
	cout << "in global print(): about to print mat.print()\n";
	m.print();
}
