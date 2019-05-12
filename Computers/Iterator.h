#pragma once
#include "Tree.cpp"

template <class T>
class Iterator
{
private:
	Tree<T>* tree;						//��������� �� ������, �� ������� ��������� ��������
	Node<T>* current;					//��������� �� ������� �������

public:
	Iterator(Tree<T>& tree)
	{
		this->tree = &tree;
		current = tree.begin();
	}
	~Iterator()
	{

	}
	void operator ++();					//������� � ���������� ��������
	void operator --();					//������� � ����������� ��������
	void operator +=(int count);		//������������ �������� �� count ��������� ������	
	void operator -=(int count);		//������������ �������� �� count ��������� �����
	bool operator == (Node<T>* root);	//���������� true, ���� �������� ��������� �� root, � false, ���� �� ���������
	bool operator != (Node<T>* root);	//���������� true, ���� �������� �� ��������� �� root, � false, ���� ���������
	void operator= (Node<T>* root);		//������������� �������� �� root
	T operator*();						//�������������� ���������
};

