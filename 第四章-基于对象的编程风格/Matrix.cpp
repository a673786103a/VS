#include "Matrix.h"


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

void test08() {
	Matrix m1(3, 4);
	Matrix m2(3, 4);
	cout << m1 << m2;
	Matrix m3 = m1 + m2;
	cout << m3;
}
ostream& operator<<(ostream& os, const Matrix& m) {
	for (int i = 0; i < m.get_row(); i++) {
		for (int j = 0; j < m.get_col(); j++)
			os << m.pmat[i][j] << " ";
		os << endl;
	}
		
	os << endl;
	return os;
}