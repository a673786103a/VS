#pragma once

#include "Triangular.h"
class Triangular_iterator
{
public:
	Triangular_iterator();
	~Triangular_iterator();
	Triangular_iterator(int index) :_index(index - 1) {}	//用户从1开始 
	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	int operator*()const;					//重载指针运算符
	Triangular_iterator& operator++();		//前置++
	Triangular_iterator operator++(int);	//后置++

private:
	void check_intergriry()const;
	int _index;
};