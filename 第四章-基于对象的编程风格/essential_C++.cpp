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
		//��Զ��Ҫ���š��û��ǶԵġ���仰
		_length = len > 0 ? len : 1;
		_beg_pos = begin > 0 ? begin : 1;
		_next = _beg_pos - 1;	//�û���1��ʼ�����ǳ����0��ʼ
	}
	int length()const { return _length; }
	int beg_pos() const { return _beg_pos; }
	int elem(int pos)const;

	//��������mutable�������ε�ʱ�򣬺����ȿ�������Ϊconst,�ֿ����޸�_next��ֵ��
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
		//�ȼ�����������Ƿ���ͬ��һ����ϰ��
		if (this != &rhs) {
			_length = rhs._length;
			_beg_pos = rhs._beg_pos;
			_next = rhs._beg_pos - 1;
		}
		
		return *this;
	}
private:
	int _length;		//Ԫ����Ŀ
	int _beg_pos;		//��ʼλ��
	mutable int _next;		//��һ������Ŀ�ꡣ // mutable��ʾ�ı�˱�������ı������ġ������ԡ�
	static vector<int> _elems;
	//static const int size = 10;	//	OK
	//int a[size];					//	OK
};
vector<int> Triangular::_elems;
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
	double* pmat;
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



/***************************mtable��const - begin***************************************/
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
/***************************mtable��const - end*******************************************/


/*****************************thisָ��-begin********************************************/
void test03() {
	Triangular t1,t2;
	t1.copy(t2);	//  <---> copy(&t1,t2);
}
/*****************************thisָ��-end************************************************/
int main()
{
	test01();


	system("pause");
	return 0;
}