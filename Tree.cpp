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
		if (root->left && root->right)					
		{												
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

template <class T>
void Tree<T>::calculateCountOfNodes(Node<T>* root, int& count)
{
	if (root != NULL)
	{
		calculateCountOfNodes(root->left, count);
		count++;
		calculateCountOfNodes(root->right, count);
	}
}

template <class T>
void Tree<T>::fillArray(Node<T>* root, T* arr, int& index)
{
	if (root != NULL)
	{
		fillArray(root->right, arr, index);
		arr[index] = root->key;
		index++;
		fillArray(root->left, arr, index);
	}
}

template <class T>
void Tree<T>::balance(Node<T>*& root, int n, int size, T* arr)
{
	if (n == size)
	{
		root = NULL;
		return;
	}
	else
	{
		int m = (n + size) / 2;					//Выбираем средний элемент отрезка
		root = new Node<T>;
		root->key = arr[m];
		balance(root->left, n, m, arr);
		balance(root->right, m + 1, size, arr);
	}
}

template <class T>
void Tree<T>::sort(SortType sortType)
{
	int size = 0;
	calculateCountOfNodes(root, size);			//Подсчет количества элементов в дереве

	T* arr = new T[size];
	T temp;
	int index = 0;
	fillArray(root, arr, index);
	
	temp.changeField();

	if (sortType == SORTTYPE_FORWARD)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (arr[i] < arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (arr[i] > arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

	balance(root, 0, size, arr);
	delete[]arr;
}

template <class T>
void Tree<T>::writeFile(string fileName)
{
	ofstream fout(fileName, ios::out);		//Открытие файла для записи
	if(fout.is_open())
		writeFilePrivate(root, fout);		//Вызов рекурсивной функции для записи в файл
	fout.close();							//Закрытие файла
}

template <class T>
void Tree<T>::writeFilePrivate(Node<T>* Tree, ofstream& fout)
{
	if (root != NULL)
	{
		if (Tree)
		{
			writeFilePrivate(Tree->left, fout);		//Рекурсивная функция для вывода в файл левого поддерева
			fout << Tree->key << endl;						//Записываем текущий узел в файл с помощью перегрузки
			writeFilePrivate(Tree->right, fout);	//Рекурсивная функция для вывода в файл правого поддерева
		}
	}
}

template <class T>
void Tree<T>::readFile(string fileName)
{
	T temp;									//Временный объект для чтения данных
	ifstream fin(fileName, ios::in);		//Открытие файла для чтения

	while (fin >> temp)						//Чтение из файла с помощью перегрузки
		this->add(temp);

	fin.close();							//Закрытие файла
}

template <class T>
void Tree<T>::writeToBinary(BinaryFile<T> &obj)
{
	if (obj.isOpenForWrite())
		writeToBinaryPrivate(root, obj);
}

template <class T>
void Tree<T>::writeToBinaryPrivate(Node<T>* root, BinaryFile<T>& obj)
{
	if (root != NULL)
	{
		if (root)
		{
			writeToBinaryPrivate(root->left, obj);		//Рекурсивная функция для вывода в бинарный файл левого поддерева
			obj.write(root->key);						//Записываем текущий узел в бинарный файл
			writeToBinaryPrivate(root->right, obj);		//Рекурсивная функция для вывода в бинарный файл правого поддерева
		}
	}
}

template <class T>
void Tree<T>::readFromBinary(BinaryFile<T>& obj)
{
	T temp;									//Временный объект для чтения данных

	if (obj.isOpenForRead())
	{
		while (true)						
		{
			obj.read(temp);
			if (obj.endFile())
				break;
			this->add(temp);
		}
	}
}
