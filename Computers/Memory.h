#pragma once
#include "ElectronicDevice.h"

class Memory : virtual public ElectronicDevice
{
protected:
	string memoryType;	//Тип оперативной памяти
	int capacity;		//Объем оперативной памяти

public:
	Memory(string mdl = "", int cst = 0, string memtype = "", int cap = 0) : ElectronicDevice(mdl, cst)
	{
		memoryType = memtype;
		capacity = cap;
	}
	~Memory()
	{

	}
	Memory(const Memory& other)
	{
		this->cost = other.cost;
		this->model = other.model;
		this->memoryType = other.memoryType;
		this->capacity = other.capacity;
	}

	void setMemoryType(string memtype);
	void setCapacity(int cap);
	string getMemoryType() const;
	int getCapacity() const;
	virtual void title() override;								//Заголовок с именем класса
	virtual void header() override;								//Заголовок таблицы

	void change();												//Изменяет поля в объекте
	void search(bool* flag);									//Возвращает объект с полями для поиска
	void changeField();											//Изменяет поле, объявленное в field

	bool isEqual(Memory& other);								//Возвращает true, если this равен other по полю, указанному field
	bool isEqual(Memory& other, bool* flag);					//Возвращает true, если this равен other по полям из flag
	bool operator == (Memory& other);							//Возвращает true, если объекты равны по всем полям
	bool operator >(Memory& other);								//Возвращает true, если this больше other по полю, указанному в field
	bool operator <(Memory& other);								//Возвращает true, если this меньше other по полю, указанному в field
	friend istream& operator >> (istream& in, Memory& obj);
	friend ostream& operator << (ostream& out, Memory& obj);
	friend ifstream& operator >> (ifstream& fin, Memory& obj);
	friend ofstream& operator << (ofstream& fout, Memory& obj);
	void writeToBinary(ofstream& out, Memory& obj);				//Записывает объект obj в бинарный файл
	void readFromBinary(ifstream& in, Memory& obj);				//Читает объект obj из бинарного файла
};