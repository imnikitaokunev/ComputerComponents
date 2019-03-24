#pragma once
#include "Computer.h"
#include "Tree.h"
#include "Tree.cpp"
#include "Stack.h"
#include "Stack.cpp"

template <class T>
class Interface
{
private:
	T obj;

public:
	void menu();
	void fun();
};

