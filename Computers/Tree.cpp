#pragma once
#include "Tree.h"

template <class T>
void Tree<T>::add(T obj)
{
	addPrivate(root, obj);
}

template <class T>
void Tree<T>::addPrivate(root, T obj)
