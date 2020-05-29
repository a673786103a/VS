#pragma once
#include "num_sequence.h"
#include <vector>
using namespace std;
class Triangular :
	public num_sequence
{
public:
	Triangular() {}
	Triangular(int len, int beg_pos = 1) :num_sequence((len > 0 ? len : 1), (beg_pos > 0 ? beg_pos : 1), &_elems) {
		_length = (len > 0 ? len : 1);
		_beg_pos = (beg_pos > 0 ? beg_pos : 1);
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
		int end_pos = pos + _length;	//左闭右开
		if (_elems.size() < end_pos)
			gen_elems(end_pos);			//对用户来讲，第end_pos个，也就是一共end_pos个
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

