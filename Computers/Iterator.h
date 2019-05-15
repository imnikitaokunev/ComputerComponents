#pragma once
#include "Tree.cpp"

template <class T>
class Iterator
{
private:
	Tree<T>* tree;						//Указатель на дерево, на которое ссылается итератор
	Node<T>* current;					//Указатель на текущий элемент

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
	void operator ++();						//Переход к следующему элементу
	void operator --();						//Возврат к предыдущему элементу
	void operator +=(int count);			//Переставляет итератор на count элементов вперед	
	void operator -=(int count);			//Переставляет итератор на count элементов назад
	bool operator == (Node<T>* root);		//Вовзращает true, если итератор указывает на root, и false, если не указывает
	bool operator != (Node<T>* root);		//Вовзращает true, если итератор не указывает на root, и false, если указывает
	bool operator != (Iterator<T>& other);	//Возвращает true, если итераторы указывают на разные элементы
	void operator= (Node<T>* root);			//Устанавливает итератор на root
	void operator=(Iterator<T>& other);		//Копирует данные из other в текущий итератор
	T& operator*();							//Разыменовывает указатель
};

