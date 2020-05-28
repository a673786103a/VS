#pragma once
#include "LibMat.h"
#include <string>
#include <iostream>
using namespace std;
class Book : public LibMat
{
public:
	Book(){}
	Book(const string& title, const string& author) :_title(title), _author(author) {
		cout << "Book::Book(" << _title << "," << _author << ") constructor.\n";
	}
	virtual ~Book() {
		cout << "Book::~Book() destructor!\n";
	}
	virtual void print() const;
	const string& title()const;
	const string& author()const;
protected:
	string _title;
	string _author;
};

