

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <list>
#include <deque>
#include <functional>
using namespace std;

template<typename IteratorType,typename elemType>
IteratorType _find(IteratorType first, IteratorType last,const elemType& val) {

	for (; first != last; first++) {
		if (*first == val)
			return first;
	}
	return last;
}

//find修改版，迭代器泛型对list和vector两种序列型容器的查找
void test01() {

	int a1[] = { 1,2,3,4,5 };
	double a2[] = { 1.2, 3.5, 3.5 };
	string a3[] = { "C++","python","java","golang" };
	vector<int> v(a1, a1 + 5);
	list<string> lt(a3, a3 + 4);


	//1.
	int* pia = _find<int*,int>(a1, a1 + 5, 3);
	if (pia != pia + 5) {
		cout << "yes" << endl;
	}

	//2.
	vector<int>::iterator it;
	it = _find<vector<int>::iterator, int>(v.begin(), v.end(), 3);
	if (it != v.end()) {
		cout << "yes2" << endl;
	}

	//3.list不支持随机迭代器和[]
	list<string>::iterator it2;
//	it2[3];
//	*(it2 + 3);
	it2 = _find<list<string>::iterator, string>(lt.begin(), lt.end(), "java");
	if (it2 != lt.end())
		cout << "yes3" << endl;
}
//deque序列型容器是否支持[]、随机迭代器、顺序迭代器
void test02() {
	deque<int> d = { 1,2,3,4,5 };
	deque<int>::iterator it;
	d[3];
	//*(it + 3);	error
	for (it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test03() {
	int a1[] = { 1,2,3,5,7,9 };
	int a2[] = { 33,44,55,66 };
	list<int> lt(a1, a1 + 6);
	list<int>::iterator it = find(lt.begin(), lt.end(),10);
	lt.insert(it, a2, a2 + 4);
	for ( it = lt.begin(); it != lt.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//search泛型算法
bool mypredict(int i,int j) {
	return i % j == 0;
}
void test04() {
	vector<int> v1 = { 1,2,3,4,5,6 };
	vector<int> v2 = { 6,4,5 };
	//search() 函数的第一种语法格式，其底层是借助 == 运算符实现的
	vector<int>::iterator it = search(v1.begin(), v1.end(), v2.begin(),v2.end());
	vector<int>::iterator it2 = search(v1.begin(), v1.end(), v2.begin(), v2.end(),mypredict);
	if (it == v1.end()) {
		cout << "不存在v2子序列" << endl;
	}
	else {
		cout << (it - v1.begin()) << endl;
	}

	if (it2 == v1.end()) {
		cout << "不存在有连续能被整除的序列" << endl;
	}
	else {
		cout << (it2 - v1.begin()) << endl;
	}
}

//返回原vector中小于或大于指定值的所有元素-begin
bool less_than(int a, int b) {
	return a < b ? true: false;
}
bool greater_than(int a, int b) {
	return a > b ? true : false;
}
//在vec中找到满足pred条件的元素并存储，最后返回新的vector容器
vector<int> filter(vector<int>& vec, int filter_value, bool(*pred)(int, int)) {
	vector<int> nvec;
	for (int i = 0; i < vec.size(); i++) {
		if (pred(vec[i], filter_value))//像不像那个谓词
			nvec.push_back(vec[i]);		
	}
		
	return nvec;
	
}
void test05() {
	vector<int> vec = { 1,2,3,4,5,6,7,8 };
	vector<int> big_vec;
	int value = 4;
	big_vec = filter(vec, value, less_than);
	for (auto i : big_vec)
		cout << i << " ";
	cout << endl;
}
//返回原vector中小于10的所有元素-end


//bind2nd的用法 - begin
template<class InputIterator,class OutInterator,class ElemType,class Comp>
OutInterator filter2(InputIterator first, InputIterator last, OutInterator at, const ElemType& val, Comp pred) {
	while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
		cout << "found value:" << *first << endl;
		*at++ = *first++;
	}
	return at;
}
void test06() {
	const int elem_size = 8;
	int ia[elem_size] = { 12,8,43,0,6,21,3,7 };
	vector<int> ivec(ia, ia + elem_size);

	//下面的数组和容器用来存储过滤后的结果
	int ia2[elem_size];
	vector<int> ivec2(elem_size);

	cout << "filter integer array for values less than 8\n";
	filter2(ia, ia + elem_size, ia2, 8, less<int>());
	cout << "filter integer array for values greater than 8\n";
	filter2(ivec.begin(), ivec.end(), ivec2.begin(), 8, greater<int>());
}
//bind2nd的用法 - end

/*************************   bind1st和bind2st - bgein   *************************************/

//底层详情见bind1st_bind2nd.txt资源文件
struct person {
	int age;
	string name;
};
/*
template<class _Arg1, class _Arg2, class _Result>
struct binary_function
{	// base class for binary functions
	typedef _Arg1 first_argument_type;
	typedef _Arg2 second_argument_type;
	typedef _Result result_type;
};
*/
//一定要继承binary_function类
struct person_filter_func : public binary_function<person, string, bool> {
	bool operator()(const person& p, const string& key) const {
		return(p.name.find(key) != string::npos);
	}
};
void disp(int val) { std::cout << val << std::endl; }
void disp_v(const person& p) { std::cout << p.age << "," << p.name << std::endl; }

void test07() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> vec;  
	//1.使用 std::less 仿函数
	//将6绑定到less<int>()的第2个参数，内部是  return(_Left < 6)
	copy_if(begin(arr), end(arr), back_inserter(vec), bind2nd(less<int>(), 6));
	for_each(vec.begin(), vec.end(), disp); // 1 2 3 4 5
	vec.clear();
	//将6绑定到less<int>()的第1个参数，内部是  return(6 > _Right)
	copy_if(begin(arr), end(arr), back_inserter(vec), bind1st(less<int>(), 6));
	for_each(vec.begin(), vec.end(), disp); // 7 8 9


	//2.使用自定义的仿函数
	std::vector<person> vecP;  
	person p1 = { 1,"jack" }; vecP.push_back(p1);
	person p2 = { 2,"rose" }; vecP.push_back(p2);
	person p3 = { 3,"jane" }; vecP.push_back(p3);
	person p4 = { 4,"shrohs" }; vecP.push_back(p4);  
	vector<person> vecRet;
	//包含关键字"ro"的person，复制到vecRet容器中
	//将“ro”绑定到person_filter_func()适配器的第二个参数
	copy_if(vecP.begin(), vecP.end(), back_inserter(vecRet), bind2nd(person_filter_func(), "ro"));
	for_each(vecRet.begin(), vecRet.end(), disp_v);

}


/*************************   bind1st和bind2st - end   *************************************/

/********************************* 语法小插曲-begin *************************************************/
class A {
public:
	int i;
	A(): i(10) {
		cout << "A()" << endl;
	}
	A(int x) {
		i = x;
	}
	bool operator()(int x) {
		cout << "x  = " << x << endl;
		return 1;
	}

};
void test09() {
	A();		//调用A()
	A(2);		//调用A(int x)
	A a;
	a(3);		//函数对象 调用bool operator()(int x)
}
/********************************* 语法小插曲-end *************************************************/
int main()
{
	
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();

	system("pause");
	return 0;
}