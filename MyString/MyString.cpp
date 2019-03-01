// MyString implementation file
#include "MyString.h"

using namespace std;

// Default Constructor
MyString::MyString()
{
	str = new char[1];
	str[0] = NULL;
}


// Constructor
MyString::MyString(const char *input)
{
	str = new char[strlen(input) + 1];
	for (int i = 0; i < (strlen(input)+1); i++)
	{
		str[i] = input[i];
	}
	str[strlen(input)] = NULL;
}

// Copy Constructor
MyString::MyString(const MyString& input)
{
	cout << "copy constructor" << endl;
	int length = static_cast<int>(strlen(input.str) + 1);
	str = new char[length];
	//strcpy_s(str, strlen(input.str) + 1, input.str);
	
	str = new char[strlen(input.str) + 1];
	for (int i = 0; i < (strlen(input.str) + 1); i++)
	{
		str[i] = input.str[i];
	}
	str[strlen(input.str)] = NULL;
}

// Deconstructor
MyString::~MyString()
{
	cout << "Deconstructor" << endl;
	delete[] str;
}

// Overloaded = operator
MyString& MyString::operator = (const MyString &input)
{
	MyString temp;
	if (this != &input)
	{
		delete[] str;
		str = nullptr;
		str = new char[strlen(input.str) + 1];
		strcpy_s(str, strlen(input.str) + 1, input.str);
	}
	return temp;
}

// Overloaded + operator
MyString MyString::operator + (const MyString &input)
{
	MyString temp;

	int size = strlen(input.str) + strlen(str) + 1;

	temp.str = new char[size];
	strcpy_s(temp.str, size, str);
	strcat_s(temp.str, size, input.str);

	return temp;
}

// Overloaded == operator
bool MyString::operator == (const MyString &other)
{
	bool equals = false;
	if (strlen(str) == strlen(other.str))
	{
		int counter = 0;

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] != other.str[i])
				counter++;
		}

		if (counter != 0)
			equals = false;
		else
			equals = true;
	}
	else
		equals = false;
	return equals;
}

// Gets string
const char* MyString::c_str() 
{
	return str;
}

// Overloaded << operator
ostream &operator << (ostream &output, MyString &input) 
{
	const char* temp = input.c_str();
	output << temp;
	return output;
}