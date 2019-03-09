#pragma once
#include "Tree.h"


template <class T>
void Tree<T>::add(T obj)
{
	addPrivate(root, obj);
}

template <class T>
void Tree<T>::addPrivate(Node<T>*& root, T obj)
{
	if (root == NULL)
	{
		root = node(obj);
	}
	else if (obj < root->key)
	{
		if (root->left != NULL)
		{
			addPrivate(root->left, obj);
		}
		else
		{
			root->left = node(obj);
		}
	}
	else if (obj > root->key || obj.isEqual(root->key))
	{
		if (root->right != NULL)
		{
			addPrivate(root->right, obj);
		}
		else
		{
			root->right = node(obj);
		}
	}
}

template <class T>
Node<T>* Tree<T>::node(T obj)
{
	Node<T>* t = new Node<T>;
	t->key = obj;
	t->left = t->right = NULL;
	return t;
}

template <class T>
void Tree<T>::show()
{
	showPrivate(root);
}

template <class T>
void Tree<T>::showPrivate(Node<T>* root)
{
	if (root != NULL)
	{
		showPrivate(root->left);
		cout << root->key << endl;
		showPrivate(root->right);
	}
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
		if(root->left != NULL)
			removeTreePrivate(root->left);
		if(root->right != NULL)
			removeTreePrivate(root->right);
		delete root;
	}
	root = NULL;
}

template <class T>
void Tree<T>::remove(T key)
{
	removePrivate(root, key);
}

template <class T>
Node<T>* Tree<T>::removePrivate(Node<T>*& root, T key)
{
	Node<T>* temp;
	if (root == NULL)
		return NULL;
	else if (key < root->key)
		root->left = removePrivate(root->left, key);
	else if (key > root->key)
		root->right = removePrivate(root->right, key);
	
	else if (key == root->key)
	{
		if (root->left && root->right)					//Если у удаляемого объекта есть 2 потомка заменяем
		{												//его минимальным элементов для левого поддерева текущего элемента
			temp = findMin(root->right);
				root->key = temp->key;
				root->right = removePrivate(root->right, root->key);
		}
		else
		{
			temp = root;
				if (root->left == NULL)
					root = root->right;
				else if (root->right == NULL)
					root = root->left;
			delete temp;
		}
	}
	else
	{
		root->right = removePrivate(root->right, key);
	}
	return root;
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
void Tree<T>::showByFilter(T key, bool* flag)
{
	showByFilterPrivate(root, key, flag);
}

template <class T>
void Tree<T>::showByFilterPrivate(Node<T>* root, T key, bool* flag)
{
	if (root != NULL)
	{
		showByFilterPrivate(root->left, key, flag);
		if (root->key.isEqual(key, flag))
			cout << root->key << endl;
		showByFilterPrivate(root->right, key, flag);
	}
}
