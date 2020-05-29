#pragma once
#include "Stack.h"
#include "LIFO_Stack.h"
template<class Element>
class Peekback_Stack :public Stack
{
public:
	Peekback_Stack() {}
	Peekback_Stack(const LIFO_Stack& rhs) {
		ls = rhs;
	}
	~Peekback_Stack() {}
	Element elem(int pos) {
		return ls.peek(pos);
	}
protected:
	LIFO_Stack ls;
};

