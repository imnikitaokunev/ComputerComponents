#pragma once
#include <iostream>
#include <string>
using namespace std;

class Exception
{
protected:
	string message;

public:
	explicit Exception(string msg)
	{
		this->message = msg;
	}
	string what();
};

