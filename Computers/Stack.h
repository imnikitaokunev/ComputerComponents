#pragma once
#include <iostream>
using namespace std;

enum ActionType
{
	ACTIONTYPE_ADD,
	ACTIONTYPE_REMOVE,
	ACTIONTYPE_REMOVEALL,
	ACTIONTYPE_CHANGE
};

template <class T>
struct stackNode
{
	T key;
	stackNode<T>* next;
	ActionType action;
};

template <class T>
class Stack
{
private:
	stackNode<T> *begin;

public:
	Stack()
	{
		begin = NULL;
	}
	~Stack()
	{

	}
	void push(T key, ActionType action);
	void show();
	T pop();
};
