#include "Triangular_iterator.h"



Triangular_iterator::Triangular_iterator()
{
}
Triangular_iterator::~Triangular_iterator()
{
}
inline bool Triangular_iterator::operator==(const Triangular_iterator& rhs) const {
	return _index == rhs._index;
}
inline bool Triangular_iterator::operator!=(const Triangular_iterator& rhs) const {
	return !(*this == rhs);
}
inline int Triangular_iterator::operator*()const {
	check_intergriry();
	return Triangular::getElem(_index);
}
inline void Triangular_iterator::check_intergriry() const {
	if (_index >= Triangular::max_elems())
		//
		exit(-1);
		//throw ietrator_overflow();

	if (_index >= Triangular::elem_size())
		//���_elems.size()��ֵ��3����ʵ����4��Ԫ�أ���ôӦ����չ��length=4,��������Ϊ _index+1
		Triangular::gen_elems(_index + 1);
}
inline Triangular_iterator& Triangular_iterator::operator++() {
	//ǰ�ð汾
	++_index;
	check_intergriry();
	return *this;

}
inline Triangular_iterator Triangular_iterator::operator++(int) {
	Triangular_iterator tmp = *this;
	_index++;
	check_intergriry();
	return tmp;
}

/********************����iterator class-begin**********************************/
void test05() {
	Triangular tri(20, 12);
	Triangular::iterator it = tri.begin();
	Triangular::iterator end_it = tri.end();
	while (it != end_it) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
/********************����iterator class-end**********************************/