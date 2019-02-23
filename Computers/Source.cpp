#include "Tree.h"
#include "Tree.cpp"

int main()
{
	setlocale(LC_ALL, "rus");
	Tree<int> tree;
	tree.add(5);
	tree.add(3);
	tree.add(8);
	tree.add(4);
	tree.add(11);
	tree.add(2);
	tree.add(7);
	tree.show();

	cout << endl;
	Node<int>* ptr = tree.find(5);
	if (ptr != NULL)
	{
		cout << ptr->key;
	}
	else
	{
		cout << "Ничего не найдено." << endl;
	}
	

	cout << endl;
	system("pause");
	return 0;

}
