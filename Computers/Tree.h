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
	void showPrivate(Node<T>* root);
	Node<T>* findPrivate(Node<T>* root, T key);
	void removeTreePrivate(Node<T>*& root);
	Node<T>* removePrivate(Node<T>*& root, T key);
	Node<T>* findMin(Node<T>* root);
	void showByFilterPrivate(Node<T>* root, T key, bool* flag);
public:
	Tree()
	{
		root = NULL;
	}
	~Tree()
	{
		removeTreePrivate(root);
	}
	Node<T>* node(T key);
	void add(T obj);
	void show();
	Node<T>* find(T key);
	void removeTree();
	void remove(T key);
	void showByFilter(T key, bool* flag);
};

