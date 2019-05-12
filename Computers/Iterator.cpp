#include "Iterator.h"


template <class T>
void Iterator<T>::operator++()
{
	Node<T>* prev;
	if (current == tree->end() - 1)
	{
		current = tree->end();
	}
	else if (current->right)
	{
		current = current->right;
		while (current->left != NULL)
			current = current->left;
	}
	else
	{
		prev = current;
		current = current->parent;
		while (current->key < prev->key || (current->key).isEqual(prev->key))		
			current = current->parent;			
	}
}

template <class T>
void Iterator<T>::operator--()
{
	Node<T>* prev;
	if (current->left)
	{
		current = current->left;
		while (current->right != NULL)
			current = current->right;
	}
	else
	{
		prev = current;
		current = current->parent;
		while (current->key >= prev->key)	
			current = current->parent;
	}
}

template <class T>
void Iterator<T>::operator+=(int count)
{
	for (int i = 0; i < count; ++i)
	{
		if (current == tree->end() - 1)
			break;
		this->operator++();
	}
}

template <class T>
void Iterator<T>::operator-=(int count)
{
	for (int i = 0; i < count; ++i)
	{
		if (current == tree->begin())
			break;
		this->operator--();
	}
}

template <class T>
bool Iterator<T>::operator!=(Node<T>* root)
{
	if (current != root)
		return true;
	else
		return false;
}

template <class T>
bool Iterator<T>::operator==(Node<T>* root)
{
	if (current == root)
		return true;
	else
		return false;
}

template <class T>
void Iterator<T>::operator=(Node<T>* root)
{
	this->current = root;
}

template <class T>
T Iterator<T>::operator*()
{
	return current->key;
}


