
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
/***************************初始化的坑-begin**********************************************/
class Matrix {
public:
	Matrix(int row, int col) :row(row), col(col) {
		pmat = new double[row*col];
	}
	//①“初始化”一定调用的是这个，不是opeator=  注意区分“初始化”和“赋值”
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
	double* pmat;	//类内有指针变量，在进行拷贝操作的时候要注意。
};
//1.成员逐一初始化
void test01() {
	{
		Matrix mat(4, 4);
		//代码块
		{
			Matrix mat2 = mat;	//default member initialization,使得两个对象的pamt指针指向同一块heap，第一次释放没问题，第二次对已经释放的内存进行操作，很危险。怎么解决？  见①处
		}	//此处,mat2的destructor发生作用
	}//此处，mat的destructor发生作用
}
/****************************初始化的坑-end**********************************************/



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

