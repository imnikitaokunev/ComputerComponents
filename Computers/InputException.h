#pragma once
#include "Exception.h"

class InputException : public Exception
{
private:
	string codeOfException;					//Содержит подробную информацию об ошибке

public:
	InputException(string msg, string code) : Exception(msg)
	{
		this->codeOfException = code;
	}
	string code();
};

void my_term();