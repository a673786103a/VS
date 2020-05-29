#pragma once
#include "num_sequence.h"
#include <iostream>
#include <vector>
using namespace std;
class Fibonacci :public num_sequence{
public:
	Fibonacci();
	//这个地方，如果基类的构造函数最后一个参数传NULL，程序可以。如果传&_elems，程序会崩溃
	Fibonacci(int len,int beg_pos = 1):num_sequence((len > 0 ? len : 1),(beg_pos > 0 ? beg_pos : 1),NULL){
		_length = (len > 0 ? len : 1);
		_beg_pos = (beg_pos > 0 ? beg_pos : 1);
	}
	Fibonacci& operator=(const Fibonacci& rhs) {
		if (this != &rhs) {
			//显式调用基类的赋值重载运算符函数
			num_sequence::operator=(rhs);
		}
		this->_length = rhs._length;
		this->_beg_pos = rhs._beg_pos;	
		return *this;
	}
	Fibonacci(const Fibonacci& rhs):num_sequence(rhs) {
		this->_length = rhs._length;
		this->_beg_pos = rhs._beg_pos;
	}
	virtual ~Fibonacci();
	//virtual int elem(int pos) const {
	//	if (!check_intergrity(pos))
	//		return -1;
	//	if (pos > _elems.size())
	//		gen_elems(pos);
	//	return _elems[pos - 1];
	//}
	virtual string what_am_i() const { return "Fibonacci"; }
	virtual ostream& print(ostream& os /* = cout */)const {
		int pos = _beg_pos - 1;
		int end_pos = pos + _length;	//左闭右开
		if (_elems.size() < end_pos)
			gen_elems(end_pos);			//对用户来讲，第end_pos个，也就是一共end_pos个
		for (; pos != end_pos; pos++)
			os << _elems[pos] << " ";
		return os;
	}

protected:
	virtual void gen_elems(int pos) const  {
		//对用户来说，pos从1开始
		if (_elems.size() == 0) {
			_elems.push_back(1);
			_elems.push_back(1);
		}
		int i = _elems.size();
		int n1 = _elems[i - 1];
		int n2 = _elems[i - 2];
		//加入pos=10,那么对用户来说是1-10，对程序来说是0-9 ，  因此是i<pos
		cout << endl;
		for (; i < pos; i++) {
			int n3 = n1 + n2;
			_elems.push_back(n3);
			//cout << "gen_elem: " << n3 << endl;
			n1 = n2; 
			n2 = n3;
		}

	}
protected:
	int _length;
	int _beg_pos;
	static vector<int> _elems;
};

