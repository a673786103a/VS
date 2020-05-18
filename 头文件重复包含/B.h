#pragma once

#include "A.h"
#include <iostream>
class B
{
public:
	void show() {
		std::cout << "hello B.h" << std::endl;
	}
public:
	B();
	~B();
};

