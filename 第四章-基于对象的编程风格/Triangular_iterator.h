#pragma once

#include "Triangular.h"
class Triangular_iterator
{
public:
	Triangular_iterator();
	Triangular_iterator(int index) :_index(index - 1) {}	//�û���1��ʼ 
	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	int operator*()const;
	Triangular_iterator& operator++();		//ǰ��++
	Triangular_iterator operator++(int);	//����++
	~Triangular_iterator();
private:
	void check_intergriry()const;
	int _index;
};