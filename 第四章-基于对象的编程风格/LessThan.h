#pragma once
#include <vector>
#include <iostream>
using namespace std;
class LessThan
{
public:
	LessThan();
	LessThan(int val) :_val(val) {}
	int comp_val()const;			
	void comp_val(int nval);
	bool operator()(int value)const;
	int count_less_than(const vector<int>& vec, int comp);
	void print_less_than(const vector<int>& vec, int comp, ostream& os = cout);
	~LessThan();
private:
	int _val;
};
void test06();
