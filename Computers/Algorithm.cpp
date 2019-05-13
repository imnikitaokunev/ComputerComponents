#include "Algorithm.h"

template <class T>
void Algorithm<T>::search(Node<T>* begin, Node<T>* end, T& value, bool* flag)
{
	Iterator<T> iterator(*tree);
	iterator = begin;
	int count = 0;					//Количество найденных элементов

	value.title();
	cout << endl;
	value.header();

	while (iterator != end)
	{
		if (value.isEqual((*iterator), flag))
		{
			++count;
			cout << *iterator << endl;
		}
		++iterator;
	}

	cout << endl << "Всего найдено элементов: " << count << endl;
}