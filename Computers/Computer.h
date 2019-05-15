#pragma once
#include "CPU.h"
#include "GraphicsCard.h"
#include "Memory.h"

class Computer : public CPU, public Memory, public GraphicsCard
{
private:
	int drive;	//Объем жесткого диска

public:
	Computer(string mdl = "", int cst = 0, int crs = 0, int freq = 0, int mem = 0,
		string memtype = "", int cpc = 0, int dr = 0)
		: ElectronicDevice(mdl, cst), CPU(mdl, cst, crs, freq), GraphicsCard(mdl, cst, mem), Memory(mdl, cst, memtype, cpc)
	{
		drive = dr;
	}
	~Computer()
	{

	}
	Computer(const Computer& other)
	{
		this->cost = other.cost;
		this->model = other.model;
		this->countOfCores = other.countOfCores;
		this->baseFrequency = other.baseFrequency;
		this->memorySize = other.memorySize;
		this->memoryType = other.memoryType;
		this->capacity = other.capacity;
		this->drive = other.drive;
	}

	void setDrive(int dr);
	int getDrive() const;
	virtual void title() override;									//Заголовок с именем класса
	virtual void header() override;									//Заголовок таблицы

	void change();													//Изменяет поля в объекте
	void search(bool *flag);										//Возвращает объект с полями для поиска
	void changeField();												//Изменяет поле, объявленное в field

	bool isEqual(Computer& other);									//Возвращает true, если this равен other по полю, указанному field
	bool isEqual(Computer& other, bool* flag);						//Возвращает true, если this равен other по полям из flag
	bool operator == (Computer& other);								//Возвращает true, если объекты равны по всем полям
	bool operator >(Computer& other);								//Возвращает true, если this больше other по полю, указанному в field
	bool operator <(Computer& other);								//Возвращает true, если this меньше other по полю, указанному в field
	friend istream& operator >> (istream& in, Computer& obj);
	friend ostream& operator << (ostream& out, Computer& obj);
	friend ifstream& operator >> (ifstream& fin, Computer& obj);
	friend ofstream& operator << (ofstream& fout, Computer& obj);
	void writeToBinary(ofstream& fout, Computer& obj);				//Записывает объект obj в бинарный файл
	void readFromBinary(ifstream& fin, Computer& obj);				//Читает объект obj из бинарного файла
};
