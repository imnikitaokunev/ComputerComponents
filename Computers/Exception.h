#pragma once
#include <iostream>
#include <string>
using namespace std;

class Exception
{
protected:
	string message;					//Сообщение об ошибке

public:
	explicit Exception(string msg)
	{
		this->message = msg;
	}
	string what();
};
