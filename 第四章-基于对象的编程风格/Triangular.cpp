
#include <iostream>
#include "Triangular.h"
using namespace std;


vector<int> Triangular::_elems;		//静态成员需要类外定义

//对于const紧随与函数参数列表之后，凡是class主体外定义者，必须同时在声明与定义后面都指定const
int Triangular::elem(int pos)const
{   
	if (pos < 0) {
		cerr << "exception!" << endl;
		exit(-1);
	}
	return _elems[pos - 1];
}  



/***************************mutable和const - begin***************************************/
int sum(const Triangular& tr) {
	if (!tr.length())
		return 0;
	int val, sum = 0;
//	tr.next_reset(); //error  tr是const的，无法调用非const成员函数，
	tr.next_reset();//next_rest设置成const函数，并且在内部需要修改的变量前加以mutable修饰。
	while (tr.next(val)) {
		sum += val;
	}
	return sum;
}
void test02() {
	Triangular tri(4);
}
/***************************mutable和const - end*******************************************/


/*****************************this指针-begin********************************************/
void test03() {
	Triangular t1,t2;
	t1.copy(t2);	//  <---> copy(&t1,t2);
}
/*****************************this指针-end************************************************/

/*****************************测试is_elems静态成员函数 -begin******************************************/
void test04() {
	Triangular::gen_elem_to_value(10000000);
	Triangular::display();
	char ch;
	bool more = true;
	while (more) {
		cout << "Enter value:";
		int ival;	cin >> ival;
		bool is_elem = Triangular::is_elem(ival);
		cout << ival << (is_elem ? "  is" : "is not ") << "an element in the Triangular series. \n" << "Another value?(y/n)";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
			more = false;
	}
	
}
/*****************************测试is_elems静态成员函数 -end******************************************/

ostream& operator<<(ostream& os, const Triangular& rhs) {
	os << "(" << rhs.beg_pos() << "," << rhs.length() << ")";
	rhs.display(os);
	return os;
}
istream& operator>>(istream& is,  Triangular& rhs) {
	char c1, c2;
	int bp, len;
	is >> c1 >> bp >> c2 >> len;		//(2,6)
	rhs.set_beg_len(bp, len);			
	rhs.gen_elems(bp, len);		
	return is;
}

/*****************************测试operator<<函数 -begin******************************************/
void test07() {
	Triangular tri(6, 3);
	//tri.gen_elems(3, 6);	//生成起始为3，长度为6的序列
	cout << tri << endl;

	Triangular tri2;
	cin >> tri2;
	cout << tri2 << endl;
}
/*****************************测试operator<<函数 -end******************************************/