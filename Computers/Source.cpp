#include "Tree.h"

int main()
{
	setlocale(LC_ALL, "rus");
	GraphicsCard obj;
	cin >> obj;
	obj.title();
	cout << endl;
	obj.header();
	cout << obj << endl << obj << endl;


	cout << endl;
	system("pause");
	return 0;

}
