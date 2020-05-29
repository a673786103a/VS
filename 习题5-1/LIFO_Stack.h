#pragma once
#include "Stack.h"
#include <vector>
using namespace std;
template<class Element>
class LIFO_Stack :public Stack
{
public:
	LIFO_Stack();
	~LIFO_Stack();
	virtual void pop() {
		if (empty())
			exit(-1);
		_elems.pop_back();
	}
	virtual void push(const Element& e) {
		_elems.push_back(e);
	}
	virtual int size() const {
		return _elems.size();
	}
	virtual bool empty() const {
		return _elems.size() == 0;
	}
	virtual void print()const {
		vector<Element>::iterator it = _elems.begin();
		vector<Element>::iterator it_end = _elems.end();;
		for (; it != it_end; i++) {
			cout << (*it) << " ";
		}
		cout << endl;
	}
	virtual Element peek(int pos) const {
		if(pos < _elems.size())
			return _elems[pos];
		return "error position!";
	}
protected:
	vector<Element> _elems;
};

