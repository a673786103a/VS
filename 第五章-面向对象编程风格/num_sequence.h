#pragma once

#include <iostream>
#include <vector>
using namespace std;
class num_sequence
{
public:
	virtual ~num_sequence(){
		delete _relems;	//释放这个为什么会错？
	}
	int elem(int pos) const {
		if (!check_intergrity(pos) || !_relems)
			return -1;
		if (pos > (*_relems).size())
			gen_elems(pos);
		return (*_relems)[pos - 1];
	}
	virtual string what_am_i() const = 0;
	static int max_elems() { return _max_elems; }
	int length() const{ return _length; }
	int beg_pos() const{ return _beg_pos; }
	virtual ostream& print(ostream& os = cout) const = 0;
	//这么写对吗
	num_sequence(const num_sequence& rhs) {
		if (_relems != NULL) {
			delete _relems;
			_relems = NULL;
		}
		_relems = new vector<int>;
		this->_length = rhs._length;
		this->_beg_pos = rhs._beg_pos;
		for (int i = 0; i < (*_relems).size(); i ++)
			(*_relems).push_back((*_relems)[i]);
	}
	num_sequence& operator=(const num_sequence& rhs) {
		if (_relems != NULL) {
			delete _relems;
			_relems = NULL;
		}
		_relems = new vector<int>;
		this->_length = rhs._length;
		this->_beg_pos = rhs._beg_pos;
		for (int i = 0; i < (*_relems).size(); i++)
			(*_relems).push_back((*_relems)[i]);
		return *this;
	}
protected:
	//num_sequence(){}
	num_sequence(int length = 1,int beg = 1,vector<int>* v = NULL):
		_length(length>0?length:1),_beg_pos(beg>0?beg:1),_relems(v){
	
	}
	
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
	int _length;
	int _beg_pos;
	vector<int>* _relems;
};
ostream& operator<< (ostream& os, const num_sequence& ns);
void display(ostream& os, const num_sequence* ns, int pos);