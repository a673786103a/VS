#include "Matrix.h"


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