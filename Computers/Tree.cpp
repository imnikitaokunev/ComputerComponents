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
	/* Если корень пуст, возвращаем новый узел */
	if (root == NULL)
	{
		return node(key);
	}
	/* Иначе рекурсивно проходим по дереву в поисках места */
	if (key < root->key)
	{
		root->left = addPrivate(root->left, key);
		//Родитель - левый элемент родителя текущего элемента
		root->left->parent = root;
	}
	else if (key > root->key || key.isEqual(root->key))
	{
		root->right = addPrivate(root->right, key);
		//Родитель - правый элемент родителя текущего элемента
		root->right->parent = root;
	}

	/* Возвращаем указатель */
	return root;
}

template <class T>
void Tree<T>::removeTree()
{
	removeTreePrivate(root);
	this->root = nullptr;
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
	Node<T>* y = ptr;	//Указатель на элемент, который мы будем удалять

	if (y->left != NULL && y->right != NULL)		//Если у удаляемого элемента 2 ребенка
	{
		y = findMin(y->right);
	}

	Node<T>* child;		//Указатель на ребенка удаляемого элемента

	if (y->left != NULL)					//Если у удаляемого элемента есть левый ребенок
		child = y->left;					//child указывает на левого
	else
		child = y->right;					//Иначе child указывает на прового

	if (child != NULL)
		child->parent = y->parent;

	if (y->parent == NULL)					//Если удаляемый элемент - корень дерева, то корень дерева - его ребенок child
	{
		root = child;
	}
	else									//Если y - не корень дерева
	{
		if (y == (y->parent)->left)			//Если y слева от его родителя
			(y->parent)->left = child;		//Теперь вместо y слева от родителя будет child
		else
			(y->parent)->right = child;		//Если y - правый сын, то теперь справа будет child
	}
	if (y != ptr)
		ptr->key = y->key;					//Если y - не удаляемый элемент, переносим ключ

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

template <class T>
int Tree<T>::height(Node<T>* t) {
	int h = 0;
	if (t != NULL) {
		int l_height = height(t->left);
		int r_height = height(t->right);
		int max_height = __max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

template <class T>
int Tree<T>::height()
{
	return height(this->root);
}
