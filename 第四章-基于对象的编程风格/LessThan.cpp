#include "LessThan.h"
#include <algorithm>
using namespace std;


LessThan::LessThan()
{
}
LessThan::~LessThan()
{
}
int LessThan::comp_val()const  { return _val; }
void LessThan::comp_val(int nval) { _val = nval; }
bool LessThan::operator()(int value) const {
	return value < _val;
}
//vec中小于comp的个数
int LessThan::count_less_than(const vector<int>& vec, int comp) {
	int cnt = 0;
	LessThan lt(comp);
	for (int i = 0; i < vec.size(); i++) {
		//if (lt(vec[i]))
		if(lt.operator()(vec[i]))		//等价写法
			cnt++;
	}
	return cnt;
}
void LessThan::print_less_than(const vector<int>& vec, int comp, ostream& os /* = cout */) {
	LessThan lt(comp);
	vector<int>::const_iterator it = vec.begin();
	vector<int>::const_iterator it_end = vec.end();
	//function object可以当做参数传递给泛型算法
	for (; (it = find_if(it, it_end, lt)) != it_end; it++) {
		os << *it << " ";
	}
	os << endl;
}

/********************************测试LessThan类-begin**********************************/
void test06() {
	vector<int> vec = { 14,26,74,3,23,43,68,9,6,53 };
	int comp = 40;
	LessThan lt(comp);
	cout << "The number of less than "<< comp << " is " << lt.count_less_than(vec,comp) << endl;
	cout << "All of the elements that less than comp: "; 
	lt.print_less_than(vec, comp);
}
/********************************测试LessThan类-end**********************************/