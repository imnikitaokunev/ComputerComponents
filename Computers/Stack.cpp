#include "Stack.h"

template <class T>
void Stack<T>::push(T key, ActionType action)
{
	stackNode<T>* temp = new stackNode<T>;
	temp->key = key;
	temp->next = begin;
	temp->action = action;
	begin = temp;
}

template <class T>
void Stack<T>::show()
{
	stackNode<T>* temp = begin;
	temp = begin;
	while (temp != NULL)
	{
		cout << temp->key << endl;
		temp = temp->next;
	}
}

template <class T>
T Stack<T>::pop()
{
	stackNode<T>* temp = begin;
	T key = begin->key;
	begin = begin->next;
	delete temp;
	return key;
}
