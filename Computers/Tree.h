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
	T key;			//���� ��������
	Node* left;		//��������� �� ������ �������	
	Node* right;	//��������� �� ������� �������
	Node* parent;	//��������� �� ��������
};

template <class T>
class Tree
{
private:
	template <class T>
	friend class Iterator;
	Node<T>* root;									//��������� �� ������ ������
	Node<T>* node(T key);							//������� ���� � ������ key
	Node<T>* addPrivate(Node<T>* root, T key);		//��������� ������� key � ������
	void removeTreePrivate(Node<T>*& root);			//������� ��� �������� ������
	Node<T>* findPrivate(Node<T>* root, T key);		//���������� ��������� �� ������� � ������ key
	Node<T>* findMin(Node<T>* root);				//���������� ��������� �� ����������� �������
	int height(Node<T>* root);						//���������� ������ ������

public:
	Tree()
	{
		root = NULL;
	}
	~Tree()
	{
		removeTree();
	}
	void add(T key);					//��������� ������� key � ������
	void removeTree();					//������� ��� �������� ������
	Node<T>* find(T key);				//���������� ��������� �� �������, ���������� ���� key, ��� NULL, ���� ������ �� �������
	void deleteNode(Node<T>* ptr);		//������� ������� ptr �� ������
	bool Empty();						//���������� true, ���� ������ ������, � false, ���� ���
	Node<T>* begin();					//���������� ��������� �� ������ ������� ������
	Node<T>* end();						//���������� ��������� �� �������, ��������� ����� ����� ������
	int height();						//���������� ������ ������
};

