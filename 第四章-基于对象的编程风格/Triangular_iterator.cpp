//#include "Triangular_iterator.h"		为什么包含这个头文件不行？
#include "Triangular.h"

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
		//异常处理
		exit(-1);
		//throw ietrator_overflow();

	if (_index >= Triangular::elem_size())
		//如果_elems.size()的值是3，则实际有4个元素，那么应该扩展的length=4,所以这里为 _index+1
		Triangular::gen_elems(_index + 1);
}
inline Triangular_iterator& Triangular_iterator::operator++() {
	//前置版本
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

/********************测试iterator class-begin**********************************/
void test05() {
	Triangular tri(5, 2);
	Triangular::iterator it = tri.begin();
	Triangular::iterator end_it = tri.end();

	while (it != end_it) {
		//cout << (*it) << " ";
		cout << (it.operator *()) << " ";
		++it;
	}
	cout << endl;
	
}
/********************测试iterator class-end**********************************/