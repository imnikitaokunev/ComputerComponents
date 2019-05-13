#include "Tree.h"

template <class T>
Node<T>* Tree<T>::node(T key)
{
	Node<T>* temp = new Node<T>;
	temp->key = key;
	temp->left = temp->right = NULL;
	temp->parent = NULL;
	return temp;
}

template <class T>
void Tree<T>::add(T key)
{
	if (root == NULL)
	{
		root = addPrivate(root, key);
	}
	else
	{
		addPrivate(root, key);
	}
}

template <class T>
Node<T>* Tree<T>::addPrivate(Node<T>* root, T key)
{
	/* If the tree is empty, return a new Node */
	if (root == NULL)
	{
		return node(key);
	}
	/* Otherwise, recur down the tree */
	if (key < root->key)
	{
		root->left = addPrivate(root->left, key);
		// Set parent of root of left subtree 
		root->left->parent = root;
	}
	else if (key > root->key || key.isEqual(root->key))
	{
		root->right = addPrivate(root->right, key);
		// Set parent of root of right subtree 
		root->right->parent = root;
	}

	/* return the (unchanged) Node pointer */
	return root;
}

template <class T>
void Tree<T>::removeTree()
{
	removeTreePrivate(root);
}

template <class T>
void Tree<T>::removeTreePrivate(Node<T>*& root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			removeTreePrivate(root->left);
		if (root->right != NULL)
			removeTreePrivate(root->right);
		delete root;
	}
	root = NULL;
}

template <class T>
Node<T>* Tree<T>::find(T key)
{
	return findPrivate(root, key);
}

template <class T>
Node<T>* Tree<T>::findPrivate(Node<T>* root, T key)
{
	if (root == NULL)
		return NULL;
	if (key == root->key)
		return root;
	else if (key < root->key)
		return findPrivate(root->left, key);
	else if (key > root->key || key.isEqual(root->key))
		return findPrivate(root->right, key);

	return NULL;
}

template<class T>
void Tree<T>::deleteNode(Node<T>* ptr)
{
	Node<T>* y = ptr;	//��������� �� �������, ������� �� ����� �������

	if (y->left != NULL && y->right != NULL)		//���� � ���������� �������� 2 �������
	{
		y = findMin(y->right);
	}

	Node<T>* child;		//��������� �� ������� ���������� ��������

	if (y->left != NULL)					//���� � ���������� �������� ���� ����� �������
		child = y->left;					//child ��������� �� ������
	else
		child = y->right;					//����� child ��������� �� �������

	if (child != NULL)
		child->parent = y->parent;

	if (y->parent == NULL)					//���� ��������� ������� - ������ ������, �� ������ ������ - ��� ������� child
	{
		root = child;
	}
	else									//���� y - �� ������ ������
	{
		if (y == (y->parent)->left)			//���� y ����� �� ��� ��������
			(y->parent)->left = child;		//������ ������ y ����� �� �������� ����� child
		else
			(y->parent)->right = child;		//���� y - ������ ���, �� ������ ������ ����� child
	}
	if (y != ptr)
		ptr->key = y->key;					//���� y - �� ��������� �������, ��������� ����

	delete y;
}

template <class T>
Node<T>* Tree<T>::findMin(Node<T>* root)
{
	if (root == NULL)
		return NULL;
	else if (root->left == NULL)
		return root;
	else
		return findMin(root->left);
}

template <class T>
bool Tree<T>::Empty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

template <class T>
Node<T>* Tree<T>::begin()
{
	Node<T>* _begin = this->root;
	if (this->root == NULL)
	{
		return NULL;
	}
	else
	{
		while (_begin->left != NULL)
		{
			_begin = _begin->left;
		}
		return _begin;
	}
}

template <class T>
Node<T>* Tree<T>::end()
{
	Node<T>* _end = this->root;
	if (_end == NULL)
	{
		return NULL;
	}
	else
	{
		while (_end->right != NULL)
		{
			_end = _end->right;
		}
		return _end + 1;
	}
}
