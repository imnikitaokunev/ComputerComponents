#pragma once
#include "CPU.h"

class GraphicsCard : virtual public ElectronicDevice
{
protected:
	int memorySize;	//Объем видеопамяти
	
public:
	GraphicsCard(string mdl = "", int cst = 0, int mem = 0) : ElectronicDevice(mdl, cst)
	{
		memorySize = mem;
	}
	~GraphicsCard()
	{

	}
	GraphicsCard(const GraphicsCard& other)
	{
		this->cost = other.cost;
		this->model = other.model;
		this->memorySize = other.memorySize;
	}

	void setMemorySize(int mem);
	int getMemorySize() const;
	virtual void title() override;										//Заголовок с именем класса
	virtual void header() override;										//Заголовок таблицы

	void change();														//Изменяет поля в объекте
	void search(bool* flag);											//Возвращает объект с полями для поиска
	void changeField();													//Изменяет поле, объявленное в field

	bool isEqual(GraphicsCard& other, bool* flag);						//Возвращает true, если this равен other по полю, указанному field
	bool isEqual(GraphicsCard& other);									//Возвращает true, если this равен other по полям из flag
	bool operator == (GraphicsCard& other);								//Возвращает true, если объекты равны по всем полям
	bool operator >(GraphicsCard& other);								//Возвращает true, если this больше other по полю, указанному в field
	bool operator <(GraphicsCard& other);								//Возвращает true, если this меньше other по полю, указанному в field
	friend istream& operator >> (istream& in, GraphicsCard& obj);
	friend ostream& operator << (ostream& out, GraphicsCard& obj);
	friend ifstream& operator >> (ifstream& fin, GraphicsCard& obj);
	friend ofstream& operator << (ofstream& fout, GraphicsCard& obj);
	void writeToBinary(ofstream& fout, GraphicsCard& obj);				//Записывает объект obj в бинарный файл
	void readFromBinary(ifstream& fin, GraphicsCard& obj);				//Читает объект obj из бинарного файла
};
