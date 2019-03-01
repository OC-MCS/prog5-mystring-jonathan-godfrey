// test driver code goes here

#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace std;

int main()
{	
	cout << "Test default constructor" << endl;
	MyString empty;
	cout << "test 1: " << empty << endl << endl;

	cout << "Test constructor" << endl;
	MyString filled("this should work");
	cout << "test 2: " << filled << endl << endl;

	cout << "Test overloaded + and = operators" << endl;
	MyString s1("hello");
	MyString s2(" world");
	MyString s3;
	s3 = s1 + s2;
	cout << "test 3: " << s3 << endl << endl;

	cout << "Test overloaded == operator" << endl;
	cout << "test 4: ";
	if (s1 == s2)
		cout << "s1 is equal to s2" << endl << endl;
	else
		cout << "s1 is not equal to s2" << endl << endl;
	
	return 0;
}