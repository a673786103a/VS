#pragma once
template<class Element>
class Stack
{
public:
	Stack() {}
	virtual ~Stack() {}
	virtual void pop() = 0;
	virtual void push(const Element& e) = 0;
	virtual int size()const = 0 ;
	virtual bool empty()const = 0;
	virtual void print() const = 0;
	virtual Element peek(int pos) const = 0;
	
};

