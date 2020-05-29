#pragma once
#include "num_sequence.h"
#include <vector>
using namespace std;
class Triangular :
	public num_sequence
{
public:
	Triangular() {
		_length = 1;
		_beg_pos = 1;
	}
	Triangular(int len, int beg_pos = 1) :num_sequence((len > 0 ? len : 1), (beg_pos > 0 ? beg_pos : 1),NULL) {
		_length = (len > 0 ? len : 1);
		_beg_pos = (beg_pos > 0 ? beg_pos : 1);
	}
	Triangular(const Triangular& rhs) :num_sequence(rhs) {
		this->_length = rhs._length;
		this->_beg_pos = rhs._beg_pos;
	}
	Triangular& operator=(const Triangular& rhs) {
		if (this != &rhs) {
			//��ʽ���û���ĸ�ֵ�������������
			num_sequence::operator=(rhs);
		}
		this->_length = rhs._length;
		this->_beg_pos = rhs._beg_pos;
		return *this;
	}
	virtual ~Triangular(){}
	//virtual int elem(int pos) const {
	//	if (!check_intergrity(pos))
	//		return -1; 
	//	if (pos > _elems.size())
	//		gen_elems(pos);
	//	return _elems[pos - 1];
	//}
	virtual string what_am_i() const { return "Triangular"; }
	virtual ostream& print(ostream& os /* = cout */)const {
		int pos = _beg_pos - 1;
		int end_pos = pos + _length;	//����ҿ�
		if (_elems.size() < end_pos)
			gen_elems(end_pos);			//���û���������end_pos����Ҳ����һ��end_pos��
		for (; pos != end_pos; pos++)
			os << _elems[pos] << " ";
		return os;
	}
protected:
	
	virtual void gen_elems(int pos) const {
		if (pos < 0 || pos > _max_elems) {
			cout << "invalid pos: " << pos << endl;
			return;
		}
		if (_elems.size() < pos) {
			int ix = _elems.size() ? _elems.size() + 1 : 1;
			for (; ix <= pos; ix++)
				_elems.push_back(ix*(ix + 1) / 2);
		}

	}
protected:
	int _length;
	int _beg_pos;
	static vector<int> _elems;
};

