#pragma once
#include <iostream>
#include "Iterator.cpp"
#include "OutputIterator.cpp"
#include "TextFile.cpp"
#include "BinaryFile.cpp"

using namespace std;

template <class T>
class Algorithm
{
private:
	Tree<T>* tree;						//Указатель на дерево

public:
	Algorithm(Tree<T>& tree)
	{
		this->tree = &tree;
	}
	Algorithm()
	{
		//this->tree = &tree;
	}
	~Algorithm()
	{

	}
	void search(Iterator<T>& first, Iterator<T>& last, T& value, bool* flag);						//Поиск элементов value по фильтру flag
	int calculateCountOfNodes(Iterator<T>& first, Iterator<T>& last);								//Возвращает число элементов в дереве
	T* toArray(Iterator<T>& first, Iterator<T>& last);												//Возвращает указатель на массив из элементов дерева
	void sortArray(T* arr, int size);																//Сортирует массив
	void toTree(T* arr, int first, int last);														//Заполняет дерево элементами из массива arr
	OutputIterator<T>& copy(Iterator<T>& first, Iterator<T>& last, OutputIterator<T>& result);		//Копирует элементы дерева в поток вывода
	void writeToTextFile(Iterator<T>& first, Iterator<T>& last, TextFile<T>& textFile);				//Записывает элементы в текстовый файл
	int readFromTextFile(TextFile<T>& textFile);													//Читает элементы из текстового файла
	void writeToBinaryFile(Iterator<T>& first, Iterator<T>& last, BinaryFile<T>& binaryFile);		//Записывает элементы в бинарный файл
	int readFromBinaryFile(BinaryFile<T>& binaryFile);												//Читает элементы из бинарного файла
};
