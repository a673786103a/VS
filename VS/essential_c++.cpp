

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <list>
#include <deque>
#include <functional>
#include <iterator>
using namespace std;

template<typename IteratorType,typename elemType>
IteratorType _find(IteratorType first, IteratorType last,const elemType& val) {

	for (; first != last; first++) {
		if (*first == val)
			return first;
	}
	return last;
}

//find�޸İ棬���������Ͷ�list��vector���������������Ĳ���
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

	//3.list��֧�������������[]
	list<string>::iterator it2;
//	it2[3];
//	*(it2 + 3);
	it2 = _find<list<string>::iterator, string>(lt.begin(), lt.end(), "java");
	if (it2 != lt.end())
		cout << "yes3" << endl;
}
//deque�����������Ƿ�֧��[]�������������˳�������
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
//search�����㷨
bool mypredict(int i,int j) {
	return i % j == 0;
}
void test04() {
	vector<int> v1 = { 1,2,3,4,5,6 };
	vector<int> v2 = { 6,4,5 };
	//search() �����ĵ�һ���﷨��ʽ����ײ��ǽ��� == �����ʵ�ֵ�
	vector<int>::iterator it = search(v1.begin(), v1.end(), v2.begin(),v2.end());
	vector<int>::iterator it2 = search(v1.begin(), v1.end(), v2.begin(), v2.end(),mypredict);
	if (it == v1.end()) {
		cout << "������v2������" << endl;
	}
	else {
		cout << (it - v1.begin()) << endl;
	}

	if (it2 == v1.end()) {
		cout << "�������������ܱ�����������" << endl;
	}
	else {
		cout << (it2 - v1.begin()) << endl;
	}
}

//����ԭvector��С�ڻ����ָ��ֵ������Ԫ��-begin
bool less_than(int a, int b) {
	return a < b ? true: false;
}
bool greater_than(int a, int b) {
	return a > b ? true : false;
}
//��vec���ҵ�����pred������Ԫ�ز��洢����󷵻��µ�vector����
vector<int> filter(vector<int>& vec, int filter_value, bool(*pred)(int, int)) {
	vector<int> nvec;
	for (int i = 0; i < vec.size(); i++) {
		if (pred(vec[i], filter_value))//�����Ǹ�ν��
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
//����ԭvector��С��10������Ԫ��-end


//bind2nd���÷� - begin
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

	//�������������������洢���˺�Ľ��
	int ia2[elem_size];
	vector<int> ivec2(elem_size);

	cout << "filter integer array for values less than 8\n";
	filter2(ia, ia + elem_size, ia2, 8, less<int>());
	cout << "filter integer array for values greater than 8\n";
	filter2(ivec.begin(), ivec.end(), ivec2.begin(), 8, greater<int>());
}
//bind2nd���÷� - end

/*************************   bind1st��bind2st - bgein   *************************************/

//�ײ������bind1st_bind2nd.txt��Դ�ļ�
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
//һ��Ҫ�̳�binary_function��
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
	//1.ʹ�� std::less �º���
	//��6�󶨵�less<int>()�ĵ�2���������ڲ���  return(_Left < 6)
	copy_if(begin(arr), end(arr), back_inserter(vec), bind2nd(less<int>(), 6));
	for_each(vec.begin(), vec.end(), disp); // 1 2 3 4 5
	vec.clear();
	//��6�󶨵�less<int>()�ĵ�1���������ڲ���  return(6 > _Right)
	copy_if(begin(arr), end(arr), back_inserter(vec), bind1st(less<int>(), 6));
	for_each(vec.begin(), vec.end(), disp); // 7 8 9


	//2.ʹ���Զ���ķº���
	std::vector<person> vecP;  
	person p1 = { 1,"jack" }; vecP.push_back(p1);
	person p2 = { 2,"rose" }; vecP.push_back(p2);
	person p3 = { 3,"jane" }; vecP.push_back(p3);
	person p4 = { 4,"shrohs" }; vecP.push_back(p4);  
	vector<person> vecRet;
	//�����ؼ���"ro"��person�����Ƶ�vecRet������
	//����ro���󶨵�person_filter_func()�������ĵڶ�������
	copy_if(vecP.begin(), vecP.end(), back_inserter(vecRet), bind2nd(person_filter_func(), "ro"));
	for_each(vecRet.begin(), vecRet.end(), disp_v);

}


/*************************   bind1st��bind2st - end   *************************************/

/********************************* �﷨С����-begin *************************************************/
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
void test08() {
	A();		//����A()
	A(2);		//����A(int x)
	A a;
	a(3);		//�������� ����bool operator()(int x)
}
/********************************* �﷨С����-end *************************************************/


/********************************* ����iterator-adapters -bgein ********************************/

template<class InputIterator>
void print(InputIterator fn) {
	//error C2760: �﷨����: ��������ơ���ʶ������Ԥ�ڵ�����Ϊ��;��
	//error C7510: ��iterator��: ���� �������Ƶ�ʹ�ñ����ԡ�typename��Ϊǰ׺
	//����ģ����˵���С�::����ǰ������typename,�����������֪�������ͻ��ǳ�Ա�����������������
	typename InputIterator::iterator iter;
	for ( iter = fn.begin(); iter != fn.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

void test09() {
	const int elem_size = 8;
	string ia[elem_size] = { "java","C++","C","erlang","python","go","PHP","java" };
	vector<string> ivec(ia,ia+elem_size);
	vector<string> res;

	//��һ��  back_inserter
	unique_copy(ivec.begin(), ivec.end(), back_inserter(res));
	print(res);
	//�ڶ��� inserter
	unique_copy(ivec.begin(), ivec.end(), inserter(res,res.begin()+2));//Ϊʲôû��ȥ���ظ��ģ�����
	print(res);
	//������ front_inserter
	list<string> ilst;
	unique_copy(ivec.begin(), ivec.end(), front_inserter(ilst));
	print(ilst);
}
/********************************* ����iterator-adapters -end ********************************/



/*****************************iostream-iterator -begin*****************************************/
void test10() {
	//���ñ�׼cin��cout
	istream_iterator<string> is(cin);
	istream_iterator<string> eof;	//��ָ������Ĭ�ϴ���end-of-file
	vector<string> text;
	copy(is, eof, back_inserter(text));
	sort(text.begin(), text.end());
	//�����´�½��,������ô�������������  
	ostream_iterator<string> os(cout, " ");
	copy(text.begin(), text.end(), os);

	//���ļ�����
	text.clear();
	ifstream in_file("./input_file.txt");
	ofstream out_file("./out_file.txt");
	istream_iterator<string> is2(in_file);
	copy(is2, eof,back_inserter(text));
	sort(text.begin(), text.end());
	ostream_iterator<string> os2(out_file, " ");
	copy(text.begin(), text.end(), os2);

}

/*****************************iostream-iterator -end*****************************************/


/*****************************����ż����� -begin*****************************************/
bool odd(const int& n1) {
	return n1 % 2 != 0;
}
bool even(const int& n1) {
	return n1 % 2 == 0;
}
void test11() {
	istream_iterator<int> is(cin);
	istream_iterator<int> eof;
	vector<int> text;
	copy(is, eof, back_inserter(text));
	vector<int> odd_num;
	vector<int> even_num;
	copy_if(text.begin(), text.end(), back_inserter(odd_num), odd);
	copy_if(text.begin(), text.end(), back_inserter(even_num), even);

	ofstream ofs1("odd_number.txt");
	ofstream ofs2("even_number.txt");
	if (!ofs1 || !ofs2)
		return;
	ostream_iterator<int> o1(ofs1," ");
	ostream_iterator<int> o2(ofs2, " ");
	copy(odd_num.begin(), odd_num.end(), o1);
	copy(even_num.begin(), even_num.end(), o2);


}
/*****************************����ż����� -end*****************************************/

int main()
{
	
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test09();
	//test10();
	test11();
	system("pause");
	return 0;
}