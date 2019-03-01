#pragma once
#include <iostream>
#include <cstring>
using namespace std;
// MyString class declaration goes here

class MyString {
private:
	char* str;
public:
	MyString();
	MyString(const char* input);
	MyString(const MyString& input);
	~MyString();

	MyString& operator = (const MyString &); 
	MyString operator + (const MyString &); 
	bool operator == (const MyString &other); 
	const char* c_str();
};

ostream &operator << (ostream &output, MyString &input);