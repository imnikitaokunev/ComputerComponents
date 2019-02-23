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
	else if (obj >= root->key)
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

/*
template <class T>
void Tree<T>::remove(T key)
{
	if (root != NULL)
	{
		if (root->key == key)
		{
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
			}
		}
	}
	else if (root->key < key)
	{
		remove(root->left)
	}


}
*/

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
	else if (key >= root->key)
		return findPrivate(root->right, key);


	return false;
}


