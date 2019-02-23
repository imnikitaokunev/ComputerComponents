#pragma once
#include <iomanip>
#include <iostream>
using namespace std;

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
	Node<T> *root;
	void addPrivate(Node<T>*& root, T key);
	void showPrivate(Node<T> *root);
	Node<T>* findPrivate(Node<T>* root, T key);
	void removePrivate(Node<T>* key);
public:
	Tree()
	{
		root = NULL;
	}
	~Tree()
	{
		//”далить все дерево
	}
	Node<T>* node(T key);
	void add(T obj);
	void show();
	Node<T>* find(T key);
	void remove(T key);
};

