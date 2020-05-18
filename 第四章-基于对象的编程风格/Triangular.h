#pragma once
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>
#include "Triangular_iterator.h"
using namespace std;

/*Triangular tri(8,3)
  Triangular tri(10)
*/


class Triangular {
	
public:
	//friend class Triangular_iterator;
//	friend int Triangular_iterator::operator*()const;
//	friend void Triangular_iterator::check_intergriry()const;
	Triangular() {	}
	Triangular(int len, int begin = 1) {
		//��Զ��Ҫ���š��û��ǶԵġ���仰
		_length = len > 0 ? len : 1;
		_beg_pos = begin > 0 ? begin : 1;
		_next = _beg_pos - 1;	//�û���1��ʼ�����ǳ����0��ʼ
		gen_elems(_beg_pos, len);
	}
	int length()const { return _length; }
	int beg_pos() const { return _beg_pos; }
	void set_beg_len(int beg, int len) {
		_beg_pos = beg;
		_length = len;
	}
	int elem(int pos)const;
	//��������mutable�������ε�ʱ�򣬺����ȿ�������Ϊconst,�ֿ����޸�_next��ֵ��
	bool next(int& value) const {
		if (_next < _beg_pos + _length - 1) {
			value = _elems[_next++];
			return true;
		}
		return false;
	}
	void next_reset()const {
		_next = _beg_pos - 1;
	}
	Triangular& copy(Triangular& rhs) {
		//�ȼ�����������Ƿ���ͬ��һ����ϰ��
		if (this != &rhs) {
			_length = rhs._length;
			_beg_pos = rhs._beg_pos;
			_next = rhs._beg_pos - 1;
		}
		return *this;
	}

	//һ��begin()/end()�ĳ�Ա����
public:
	typedef Triangular_iterator iterator;
	Triangular_iterator begin() const {
		return Triangular_iterator(_beg_pos);	//_beg_pos��1��ʼ��Triangular_iterator�Ĺ��캯��index�м�1����
	}
	Triangular_iterator end() const {
		return Triangular_iterator(_beg_pos + _length);
	}

public:
	static void gen_elem_to_value(int value) {
		size_t sz = _elems.size();
		if (!sz) {
			_elems.push_back(1);
			sz++;
		}
		//�����ǰ���е����һ��ֵС�ڲ����������ɺ���ֱ�����ڲ���ֵ
		while (_elems[sz - 1] < value && sz < _max_size) {
			sz++;
			_elems.push_back( ((sz*(sz + 1)) / 2));
		}
		if (sz == _max_size) {
			cout << "Triangular Sequence: oops: value too large" << value << "-- exceeds max size of"
				<< _max_size << endl;
		}

	}
	static bool is_elem(int value) {
		vector<int>::iterator it = find(_elems.begin(), _elems.end(), value);
		return it != _elems.end();
	}
	static void display(ostream& os = cout) {
		os << "Triangular: ";
		for (auto elem : _elems) 
			os << elem << " ";
		os << endl;
	}
	//����ָ�����ȵ�Ԫ��
	static void gen_elems(int length) {
		if (length < 0 || length > _max_size) {
			cout << "The length exceeds the maximum capacity of vector" << endl;
			return;
		}
		if (_elems.size() < length) {
			int ix = _elems.size() ? _elems.size() + 1 : 1;
			for(; ix <= length; ix++)
				_elems.push_back( ix*(ix + 1) / 2);
		}
			
	}
	//
	static void gen_elems(int big_pos, int len) {
		if (big_pos < 1 || len < 0 || len > _max_size) {
			cout << "gen_elems(int big_pos, int len) parameters error!" << endl;
			exit(-1);
		}
		_elems.clear();
		int ix = big_pos;
		for (int j = 1; j <= len; j++,ix++) {
			_elems.push_back(ix*(ix + 1) / 2);
		}
	}
	static int elem_size() { return _elems.size(); }
	static int max_elems() { return _max_size; }
	static int getElem(int index) { return _elems[index]; }
private:
	int _length;					//Ԫ����Ŀ
	int _beg_pos;					//��ʼλ��
	mutable int _next;				//��һ������Ŀ�ꡣ // mutable��ʾ�ı�˱�������ı������ġ������ԡ�
	static vector<int> _elems;
	static const int _max_size = 1024;		//	OK
	//int a[_max_size];					//	OK
};


void test04();
void test05();
void test07();
ostream& operator<<(ostream& os, const Triangular& rhs);
istream& operator>>(istream& is, const Triangular& ths);