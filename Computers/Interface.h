#pragma once
#include "Computer.h"
#include "Algorithm.cpp"


template <class T>
class Interface
{
private:
	T obj;

public:
	void menu();				//Меню выбора класса
	void fun(string file);		//Интерфейс работы с классом
};

