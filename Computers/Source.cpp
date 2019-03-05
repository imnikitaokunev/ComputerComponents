#include "Interface.h"
#include "Interface.cpp"

int main()
{
	setlocale(LC_ALL, "rus");
	

	//Computer obj1("L", 4);
	//obj1.header();
	//tree.add(obj1);
	//Computer obj2("C", 6);
	//tree.add(obj2);
	//Computer obj3("H", 1);
	//tree.add(obj3);
	//Computer obj4("D", 2);
	//tree.add(obj4);
	//Computer obj5("A", 5);
	//tree.add(obj5);
	//Computer obj6("B", 8);
	//tree.add(obj6);
	//tree.show();

	//cout << endl;
	//Node<Computer>* ptr = tree.find(obj4);
	//if (ptr != nullptr)
	//	tree.remove(ptr);
	//ptr = tree.find(obj4);
	//if (ptr != nullptr)
	//	tree.remove(ptr);
	//cout << endl;
	//tree.show();
	//ptr = tree.find(obj6);
	//if (ptr != nullptr)
	//	tree.remove(ptr);
	//cout << endl;
	//tree.show();
	//ptr = tree.find(obj1);
	//if (ptr != nullptr)
	//	tree.remove(ptr);
	//cout << endl;
	//tree.show();

	Interface<int> obj;
	obj.menu();


	cout << endl;
	system("pause");
	return 0;

}
