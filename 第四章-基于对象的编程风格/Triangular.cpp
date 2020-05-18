
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
/***************************��ʼ���Ŀ�-begin**********************************************/
class Matrix {
public:
	Matrix(int row, int col) :row(row), col(col) {
		pmat = new double[row*col];
	}
	//�١���ʼ����һ�����õ������������opeator=  ע�����֡���ʼ�����͡���ֵ��
	Matrix(const Matrix& m):row(m.row),col(m.col) {
		pmat = new double[row*col];
		for (int i = 0; i < row*col; i++) {
			pmat[i] = m.pmat[i];		
		}
	}
	Matrix& operator=(const Matrix& m) {
		pmat = new double[row*col];
		for (int i = 0; i < row*col; i++) {
			pmat[i] = m.pmat[i];
		}
	}
	~Matrix(){
		delete[]pmat;
	}
private:
	int row, col;
	double* pmat;	//������ָ��������ڽ��п���������ʱ��Ҫע�⡣
};
//1.��Ա��һ��ʼ��
void test01() {
	{
		Matrix mat(4, 4);
		//�����
		{
			Matrix mat2 = mat;	//default member initialization,ʹ�����������pamtָ��ָ��ͬһ��heap����һ���ͷ�û���⣬�ڶ��ζ��Ѿ��ͷŵ��ڴ���в�������Σ�ա���ô�����  ���ٴ�
		}	//�˴�,mat2��destructor��������
	}//�˴���mat��destructor��������
}
/****************************��ʼ���Ŀ�-end**********************************************/



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

