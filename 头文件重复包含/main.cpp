#include <iostream>
#include <vector>
using namespace std;


#include "A.h"
int main()
{
	vector<int> vec;
	vector<int>* v = &vec;
	delete v;


	return 0;
}