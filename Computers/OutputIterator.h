#pragma once
#include <iostream>
#include <string>
using namespace std;

template< class T>
class OutputIterator
{
private:
	const char* delim;							//Разделяет выводимые объекты
	ostream* stream;							//Поток вывода
public:
	OutputIterator(ostream& ostream)
	{
		this->stream = &ostream;
		this->delim = nullptr;
	}
	OutputIterator(ostream& ostream, const char* delim)
	{
		this->stream = &ostream;
		this->delim = delim;
	}
	~OutputIterator()
	{

	}
	OutputIterator<T>& operator= (T& value);	//Выводит на экран объект value
	OutputIterator<T>& operator*();				//Разыменовывает итератор вывода
	OutputIterator<T>& operator++();			//Переход к следующему элементу
};


