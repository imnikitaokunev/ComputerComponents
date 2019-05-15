#pragma once
#include <iostream>
using namespace std;

enum SortType
{
	SORTTYPE_FORWARD,
	SORTTYPE_BACKWARDS
};


template <class T>
struct Node
{
	T key;			//Ключ элемента
	Node* left;		//Указатель на левого потомка	
	Node* right;	//Указатель на правого потомка
	Node* parent;	//Указатель на родителя
};

template <class T>
class Tree
{
private:
	template <class T>
	friend class Iterator;
	Node<T>* root;									//Указатель на корень дерева
	Node<T>* node(T key);							//Создает узел с ключом key
	Node<T>* addPrivate(Node<T>* root, T key);		//Добавляет элемент key в дерево
	void removeTreePrivate(Node<T>*& root);			//Удаляет все элементы дерева
	Node<T>* findPrivate(Node<T>* root, T key);		//Возвращает указатель на элемент с ключом key
	Node<T>* findMin(Node<T>* root);				//Возвращает указатель на минимальный элемент
	int height(Node<T>* root);						//Возвращает высоту дерева

public:
	Tree()
	{
		root = NULL;
	}
	~Tree()
	{
		removeTree();
	}
	void add(T key);					//Добавляет элемент key в дерево
	void removeTree();					//Удаляет все элементы дерева
	Node<T>* find(T key);				//Возвращает указатель на элемент, содержащий ключ key, или NULL, если ничего не найдено
	void deleteNode(Node<T>* ptr);		//Удаляет элемент ptr из дерева
	bool Empty();						//Возвращает true, если дерево пустое, и false, если нет
	Node<T>* begin();					//Возвращает указатель на первый элемент дерева
	Node<T>* end();						//Вовзращает указатель на элемент, следующий после конца дерева
	int height();						//Возвращает высоту дерева
};

