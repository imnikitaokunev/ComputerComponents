#include "Interface.h"
#include "Interface.cpp"

void my_term()
{
	cout << "Программа аварийно завершена." << endl;
	exit(1);
}

int main()
{
	setlocale(LC_ALL, "rus");
	set_terminate(my_term);

	Interface<int> obj;
	obj.menu();

	cout << endl;
	system("pause");
	return 0;
}

