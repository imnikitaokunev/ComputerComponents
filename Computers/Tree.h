#pragma once
#include <iomanip>
#include <iostream>

template <class T>
struct Node
{
	T key;				//�������������� �����
	Node *right,		//��������� �� ������ ���������
		 *left;			//��������� �� ����� ���������
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
		//������� ��� ������
	}
	void add(T obj);
	void show();
};