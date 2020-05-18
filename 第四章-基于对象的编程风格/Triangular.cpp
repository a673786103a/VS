
#include <iostream>
#include "Triangular.h"
using namespace std;


vector<int> Triangular::_elems;		//��̬��Ա��Ҫ���ⶨ��

//����const�����뺯�������б�֮�󣬷���class�����ⶨ���ߣ�����ͬʱ�������붨����涼ָ��const
int Triangular::elem(int pos)const
{   
	if (pos < 0) {
		cerr << "exception!" << endl;
		exit(-1);
	}
	return _elems[pos - 1];
}  



/***************************mutable��const - begin***************************************/
int sum(const Triangular& tr) {
	if (!tr.length())
		return 0;
	int val, sum = 0;
//	tr.next_reset(); //error  tr��const�ģ��޷����÷�const��Ա������
	tr.next_reset();//next_rest���ó�const�������������ڲ���Ҫ�޸ĵı���ǰ����mutable���Ρ�
	while (tr.next(val)) {
		sum += val;
	}
	return sum;
}
void test02() {
	Triangular tri(4);
}
/***************************mutable��const - end*******************************************/


/*****************************thisָ��-begin********************************************/
void test03() {
	Triangular t1,t2;
	t1.copy(t2);	//  <---> copy(&t1,t2);
}
/*****************************thisָ��-end************************************************/

/*****************************����is_elems��̬��Ա���� -begin******************************************/
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
/*****************************����is_elems��̬��Ա���� -end******************************************/

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

/*****************************����operator<<���� -begin******************************************/
void test07() {
	Triangular tri(6, 3);
	//tri.gen_elems(3, 6);	//������ʼΪ3������Ϊ6������
	cout << tri << endl;

	Triangular tri2;
	cin >> tri2;
	cout << tri2 << endl;
}
/*****************************����operator<<���� -end******************************************/