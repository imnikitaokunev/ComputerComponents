#include "Interface.h"
#include "Interface.cpp"

int main()
{
	setlocale(LC_ALL, "rus");

	Interface<int> obj;
	obj.menu();

	cout << endl;
	system("pause");
	return 0;
}
