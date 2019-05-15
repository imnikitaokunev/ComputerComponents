#include "Algorithm.h"

template <class T>
void Algorithm<T>::search(Iterator<T>& begin, Iterator<T>& end, T& value, bool* flag)
{
	Iterator<T> iterator = begin;
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

template <class T>
int Algorithm<T>::calculateCountOfNodes(Iterator<T>& begin, Iterator<T>& end)
{
	Iterator<T> iterator = begin;

	int count = 0;					//Число элементов в дереве

	while (iterator != end)
	{
		++count;
		++iterator;
	}

	return count;
}

template<class T>
T* Algorithm<T>::toArray(Iterator<T>& begin, Iterator<T>& end)
{
	int count = this->calculateCountOfNodes(begin, end);
	T* arr = new T[count];

	Iterator<T> iterator;
	int i;

	for (iterator = begin, i = 0; iterator != end; ++iterator, ++i)
	{
		arr[i] = *iterator;
	}

	return arr;
}

template<class T>
void Algorithm<T>::sortArray(T* arr, int size)
{
	T temp;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template<class T>
void Algorithm<T>::toTree(T* arr, int first, int last)
{
	if (first == last)
	{
		return;
	}
	else
	{
		int medium = (first + last) / 2;
		this->tree->add(arr[medium]);
		toTree(arr, first, medium);
		toTree(arr, medium + 1, last);
	}
}

template<class T>
OutputIterator<T>& Algorithm<T>::copy(Iterator<T>& first, Iterator<T>& last, OutputIterator<T>& result)
{
	Iterator<T> iterator = first;

	while (iterator != last) {
		*result = *iterator;
		++result;
		++iterator;
	}
	return result;
}

template<class T>
void Algorithm<T>::writeToTextFile(Iterator<T>& first, Iterator<T>& last, TextFile<T>& textFile)
{
	Iterator<T> iterator = first;

	textFile.openForWrite();
	while (iterator != last)
	{
		textFile.write(*iterator);
		++iterator;
	}

	textFile.closeWrite();
}

template<class T>
int Algorithm<T>::readFromTextFile(TextFile<T>& textFile)
{
	T temp;
	int count = 0;
	temp.header();

	textFile.openForRead();
	while (true)
	{	
		textFile.read(temp);
		if (textFile.endFile())
			break;
		cout << temp << endl;
		this->tree->add(temp);
		++count;
	}
	
	textFile.closeRead();
	return count;
}

template<class T>
void Algorithm<T>::writeToBinaryFile(Iterator<T>& first, Iterator<T>& last, BinaryFile<T>& binaryFile)
{
	Iterator<T> iterator = first;

	binaryFile.openForWrite();
	while (iterator != last)
	{
		binaryFile.write(*iterator);
		++iterator;
	}

	binaryFile.closeWrite();
}

template<class T>
int Algorithm<T>::readFromBinaryFile(BinaryFile<T>& binaryFile)
{
	T temp;
	int count = 0;
	temp.header();

	binaryFile.openForRead();
	while (true)
	{
		binaryFile.read(temp);
		if (binaryFile.endFile())
			break;
		cout << temp << endl;
		this->tree->add(temp);
		++count;
	}

	binaryFile.closeRead();
	return count;
}
