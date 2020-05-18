#pragma once
#include <iostream>
using namespace std;
/***************************��ʼ���Ŀ�-begin**********************************************/
//��������
class Matrix {
public:
	friend ostream& operator<<(ostream& os, const Matrix& m);
	Matrix(int row, int col) :row(row), col(col) {
		pmat = new double*[row];
		for (int j = 0; j < row; j++)
			pmat[j] = new double[col];
		gen_elems();
	}
	//�١���ʼ����һ�����õ������������opeator=  ע�����֡���ʼ�����͡���ֵ��
	Matrix(const Matrix& m) :row(m.row), col(m.col) {
		pmat = new double*[row];
		for (int j = 0; j < row; j++)
			pmat[j] = new double[col];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				pmat[i][j] = m.pmat[i][j];
	}
	Matrix& operator=(const Matrix& m) {
		pmat = new double*[row];
		for (int j = 0; j < row; j++)
			pmat[j] = new double[col];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				pmat[i][j] = m.pmat[i][j];
	}
	Matrix operator+(const Matrix& m) {
		if (this->row != m.row || this->col != m.col)
			exit(-1);
		Matrix m3(m.row, m.col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				m3.pmat[i][j] = this->pmat[i][j] + m.pmat[i][j];
		return m3;
	}
	Matrix operator-(const Matrix& m) {
		if (this->row != m.row || this->col != m.col)
			exit(-1);
		Matrix m3(m.row, m.col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				m3.pmat[i][j] = this->pmat[i][j] - m.pmat[i][j];
		return m3;
	}
	Matrix operator*(const Matrix& m) {
		if (this->col != m.row)
			exit(-1);
		Matrix m3(this->row, m.col);
		return m3;
	}
	bool operator==(const Matrix& m) {
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (this->pmat[i][j] != m.pmat[i][j])
					return false;
		return true;
	}
	void gen_elems() {
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				pmat[i][j] = (rand() % 50);
	}
	int get_row() const { return row; }
	int get_col() const { return col; }
	
	
	


	~Matrix() {
		delete[]pmat;
	}
private:
	int row, col;
	double** pmat;	//������ָ��������ڽ��п���������ʱ��Ҫע�⡣
};
void test01();
void test08();
ostream& operator<<(ostream& os, const Matrix& m);
/****************************��ʼ���Ŀ�-end**********************************************/
