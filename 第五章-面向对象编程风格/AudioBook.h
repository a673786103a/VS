#pragma once
#include "Book.h"
class AudioBook :
	public Book
{
public:
	AudioBook(){}
	AudioBook(const string& title, const string& author, const string& narrator) :Book(title, author), _narrator(narrator) {
		cout << "Book::Book(" << _title << "," << _author << "," << _narrator << ") constructor.\n";
	}
	virtual ~AudioBook() {
		cout << "AudioBook::~AudioBook() destructor!\n";
	}
	virtual void print()const {
		cout << "Book::print() -- I am a book object!\n"
			<< "My title:" << _title << "\n"
			<< "My author:" << _author << "\n"
			<< "My narrator: " << _narrator << endl;
	}
	const string& narrator() const {
		return _narrator;
	}
protected:
	string _narrator;
};

