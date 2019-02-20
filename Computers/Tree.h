#pragma once
#include <iomanip>
#include <iostream>

template <class T>
struct Node
{
	T key;				//»нформационна€ часть
	Node *right,		//”казатель на правое поддерево
		 *left;			//”казатель на левое поддерево
};

template <class T>
class Tree
{
private:
	Node<T> root;
	void addPrivate(Node<T>* root, T obj);

public:
	Tree()
	{
		root = NULL;
	}
	~Tree()
	{
		//”далить все дерево
	}
	void add(T obj);
	void show();
};