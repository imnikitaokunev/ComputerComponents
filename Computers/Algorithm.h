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
	Tree<T>* tree;						//��������� �� ������

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
	void search(Iterator<T>& first, Iterator<T>& last, T& value, bool* flag);						//����� ��������� value �� ������� flag
	int calculateCountOfNodes(Iterator<T>& first, Iterator<T>& last);								//���������� ����� ��������� � ������
	T* toArray(Iterator<T>& first, Iterator<T>& last);												//���������� ��������� �� ������ �� ��������� ������
	void sortArray(T* arr, int size);																//��������� ������
	void toTree(T* arr, int first, int last);														//��������� ������ ���������� �� ������� arr
	OutputIterator<T>& copy(Iterator<T>& first, Iterator<T>& last, OutputIterator<T>& result);		//�������� �������� ������ � ����� ������
	void writeToTextFile(Iterator<T>& first, Iterator<T>& last, TextFile<T>& textFile);				//���������� �������� � ��������� ����
	int readFromTextFile(TextFile<T>& textFile);													//������ �������� �� ���������� �����
	void writeToBinaryFile(Iterator<T>& first, Iterator<T>& last, BinaryFile<T>& binaryFile);		//���������� �������� � �������� ����
	int readFromBinaryFile(BinaryFile<T>& binaryFile);												//������ �������� �� ��������� �����
};
