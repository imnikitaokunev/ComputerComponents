#pragma once
#include "Tree.cpp"

template <class T>
class Iterator
{
private:
	Tree<T>* tree;						//��������� �� ������, �� ������� ��������� ��������
	Node<T>* current;					//��������� �� ������� �������

public:
	Iterator()
	{
		this->tree = nullptr;
		this->current = nullptr;
	}
	Iterator(Tree<T>& tree)
	{
		this->tree = &tree;
		current = tree.begin();
	}
	
	~Iterator()
	{

	}
	void operator ++();						//������� � ���������� ��������
	void operator --();						//������� � ����������� ��������
	void operator +=(int count);			//������������ �������� �� count ��������� ������	
	void operator -=(int count);			//������������ �������� �� count ��������� �����
	bool operator == (Node<T>* root);		//���������� true, ���� �������� ��������� �� root, � false, ���� �� ���������
	bool operator != (Node<T>* root);		//���������� true, ���� �������� �� ��������� �� root, � false, ���� ���������
	bool operator != (Iterator<T>& other);	//���������� true, ���� ��������� ��������� �� ������ ��������
	void operator= (Node<T>* root);			//������������� �������� �� root
	void operator=(Iterator<T>& other);		//�������� ������ �� other � ������� ��������
	T& operator*();							//�������������� ���������
};

