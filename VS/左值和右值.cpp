#include "pch.h"
#include<iostream>
#include<vector>
using namespace std;


/*
 * һ��������ֵ����ֵ�ı�ݷ����ǣ����ܲ��ܶԱ��ʽȡ��ַ������ܣ���Ϊ��ֵ������Ϊ��ֵ

	�ǳ�����ֵ����ֻ�ܰ󶨵��ǳ�����ֵ�����ܰ󶨵�������ֵ���ǳ�����ֵ�ͳ�����ֵ��
	�������󶨵��ǳ�����ֵ����ᵼ�·ǳ�Σ�յ�������֣���Ϊ�ǳ�����ֵ��һ����ʱ���󣬷ǳ�����ֵ���ÿ��ܻ�ʹ��һ���Ѿ��������˵���ʱ����
	������ֵ���ÿ��԰󶨵��������͵�ֵ�������ǳ�����ֵ��������ֵ���ǳ�����ֵ�ͳ�����ֵ��
   
*/


const char* s[9] = { "C++","java","python","golang" ,"unity3D","erlang","PHP","JSP","java scrip"};
int index = 0;
class A {
public:
	A() {
		cout << "A�Ĺ��캯��" << endl;
		str = new char[20];
	//	str = s[index++];
		str = "hello";
	}
	~A() {
		cout << "A����������" << endl;
		delete str;
	}
	//�������õĳ�ʼֵ��������������   
	A(const A& a) {
		cout << "A�Ŀ������캯��" << endl;
	}
	A& operator=(const A& a) {
		cout << "���ظ�ֵ�����" << endl;
		//�������Ҹ�ֵ
		if (this != &a) {
			if (str != NULL) {
				delete str;
				str = NULL;
			}
			str = new char[15];
			str = s[index++];
		
		}
		return *this;
	}
public:
	 const char *str;
};


void test01() {
	int a = 10;
	int b = 20;
	int* pFlag = &a;
	string str1 = "hello ";
	string str2 = "world";
	const int &m = 1;
	//&(a + b);		��
	&(++a);
	//&(a++);		��
	&(string("sa"));
	&pFlag;
	&(str1 + str2);
	&("hello");
	//int& i = 2;	�ǳ������õĳ�ʼֵ����Ϊ��ֵ
	const int& j = 2;
}
void test02() {
	A a;			//����������
	//A a2(a);				//����a2ʱΪʲô���������������
	//A a3 = a;				//���ǳ�ʼ��  ���������ظ�ֵ�����  ���õĿ���
	//a2.operator=(a);		//���Ǹ�ֵ  ���ǳ�ʼ��  ������ÿ������캯��
	//A* p1 = new A;
	//A* p2 = new A();
	//A* p3 = p2;
}
class B {
public:
	B(){}
	B(int a){}
	void show() {
		cout << "hello world" << endl;
	}

};
int main()
{
	B b;
	//b.show();
	//test01();
	//test02();
}
