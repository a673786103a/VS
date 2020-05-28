#pragma once

#include <iostream>
using namespace std;
class num_sequence
{
public:
	num_sequence();
	virtual ~num_sequence();
	virtual int elem(int pos) const = 0;
	virtual string what_am_i() const = 0;
	static int max_elems() { return _max_elems; }
	virtual ostream& print(ostream& os = cout) const = 0;

protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_intergrity(int pos) const {
		if (pos <= 0 || pos > _max_elems) {
			cout << "invalid position : " << pos << endl;
			return false;
		}
		return true;
	}
protected:
	const static int _max_elems = 1024;
};
ostream& operator<< (ostream& os, const num_sequence& ns);
void display(ostream& os, const num_sequence* ns, int pos);