#pragma once
#include <iostream>
#include "Iterator.cpp"

using namespace std;

template <class T>
class Algorithm
{
private:
	Tree<T>* tree;						//”казатель на дерево

public:
	Algorithm(Tree<T>& tree)
	{
		this->tree = &tree;
	}
	void search(Node<T>* begin, Node<T>* end, T& value, bool* flag);
};

