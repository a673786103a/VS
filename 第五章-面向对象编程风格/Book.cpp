#include "Book.h"

const string& Book::title()const{ return _title; }
const string& Book::author() const{ return _author; }
void Book::print()const {
	cout << "Book::print() -- I am a book object!\n"
		<< "My title:" << _title << "\n"
		<< "My author:" << _author << endl;
}