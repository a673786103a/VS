#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

/*Triangular tri(8,3)		
  Triangular tri(10)
*/
class Triangular {
public:
	Triangular() {	}
//	Triangular(int len) {	}
	Triangular(int len, int begin = 1) {
		//永远不要相信“用户是对的”这句话
		_length = len > 0 ? len : 1;
		_beg_pos = begin > 0 ? begin : 1;
		_next = _beg_pos - 1;	//用户从1开始，但是程序从0开始
	}
	int length()const { return _length; }
	int beg_pos() const { return _beg_pos; }
	int elem(int pos)const;

	//当变量用mutable加以修饰的时候，函数既可以声明为const,又可以修改_next的值了
	bool next(int& value) const {
		if (_next < _beg_pos + _length - 1) {
			value = _elems[_next++];
			return true;
		}
		return false;
	}
	void next_reset()const {
		_next = _beg_pos - 1;
	}
	
	Triangular& copy(Triangular& rhs) {
		//先检查两个对象是否相同是一个好习惯
		if (this != &rhs) {
			_length = rhs._length;
			_beg_pos = rhs._beg_pos;
			_next = rhs._beg_pos - 1;
		}
		
		return *this;
	}
private:
	int _length;		//元素数目
	int _beg_pos;		//起始位置
	mutable int _next;		//下一个迭代目标。 // mutable表示改变此变量不会改变类对象的“常数性”
	static vector<int> _elems;
	//static const int size = 10;	//	OK
	//int a[size];					//	OK
};
vector<int> Triangular::_elems;
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
	double* pmat;
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



/***************************mtable和const - begin***************************************/
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
/***************************mtable和const - end*******************************************/


/*****************************this指针-begin********************************************/
void test03() {
	Triangular t1,t2;
	t1.copy(t2);	//  <---> copy(&t1,t2);
}
/*****************************this指针-end************************************************/
int main()
{
	test01();


	system("pause");
	return 0;
}