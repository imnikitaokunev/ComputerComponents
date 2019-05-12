#include "InputException.h"


string InputException::code()
{
	return this->codeOfException;
}

void my_term()
{
	cout << "Программа аварийно завершена." << endl;
	exit(1);
}
