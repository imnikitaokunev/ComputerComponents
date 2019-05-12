#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include "BinaryFile.h"
#include "BinaryFile.cpp"
using namespace std;

enum SortType
{
	SORTTYPE_FORWARD,
	SORTTYPE_BACKWARDS
};

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
	void calculateCountOfNodes(Node<T>* root, int& count);
	void fillArray(Node<T>* root, T* arr, int& index);
	void balance(Node<T>*& root, int n, int size, T* arr);
	void writeFilePrivate(Node<T>* root, ofstream& fout);
	void writeToBinaryPrivate(Node<T>* root, BinaryFile<T>& obj);

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
	void sort(SortType sortType);
	void readFile(string FileName);
	void writeFile(string fileName);
	void writeToBinary(BinaryFile<T> &obj);
	void readFromBinary(BinaryFile<T>& obj);
};


