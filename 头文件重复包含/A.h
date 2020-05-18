#pragma once

#include "B.h"
#include <iostream>
//class B;
class A
{
public:
	void show() {
		std::cout << "hello A.h" << std::endl;
	}
public:
	A();
	~A();
};
