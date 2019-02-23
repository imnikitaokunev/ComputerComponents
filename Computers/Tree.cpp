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
		cout << root->key << "  ";
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
void Tree<T>::remove(Node<T>* ptr)
{
	removePrivate(root, ptr);
}

template <class T>
void Tree<T>::removePrivate(Node<T>*& root, Node<T>* ptr)
{
	Node<T>* temp;
	if (root == NULL)
	{
		return;
	}
	else if (ptr->key < root->key)
	{
		removePrivate(root->left, ptr);
	}
	else if (ptr->key > root->key)
	{
		removePrivate(root->right, ptr);
	}
	else if (root->left != NULL && root->right != NULL)
	{
		temp = findMin(root->right);
		root->key = temp->key;
		removePrivate(root->right, root);
	}
	else if (ptr->key == root->key)
	{
		temp = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		delete temp;
	}

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
