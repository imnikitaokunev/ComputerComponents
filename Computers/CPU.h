#pragma once
#include "ElectronicDevice.h"

class CPU : virtual public ElectronicDevice
{
protected:
	int countOfCores;	//Количество ядер
	int baseFrequency;	//Базовая частота

public:
	CPU(string mdl = "", int cst = 0, int cores = 0, int freq = 0) : ElectronicDevice(mdl, cst)
	{
		countOfCores = cores;
		baseFrequency = freq;
	}
	~CPU()
	{

	}
	CPU(const CPU& other) : ElectronicDevice(other)
	{
		this->countOfCores = other.countOfCores;
		this->baseFrequency = other.baseFrequency;
	}

	void setCountOfCores(int cores);
	void setBaseFrequency(int freq);
	int getCountOfCores() const;
	int getBaseFrequency() const;
	virtual void title() override;								//Заголовок с именем класса
	virtual void header() override;								//Заголовок таблицы

	void change();												//Изменяет поля в объекте
	void search(bool* flag);									//Возвращает объект с полями для поиска
	void changeField();											//Изменяет поле, объявленное в field

	bool isEqual(CPU& other);									//Возвращает true, если this равен other по полю, указанному field
	bool isEqual(CPU& other, bool* flag);						//Возвращает true, если this равен other по полям из flag
	bool operator == (CPU& other);								//Возвращает true, если объекты равны по всем полям
	bool operator >(CPU& other);								//Возвращает true, если this больше other по полю, указанному в field
	bool operator <(CPU& other);								//Возвращает true, если this меньше other по полю, указанному в field
	friend istream& operator >> (istream& in, CPU& obj);
	friend ostream& operator << (ostream& out, CPU& obj);
	friend ifstream& operator >> (ifstream& fin, CPU& obj);
	friend ofstream& operator << (ofstream& fout, CPU& obj);
	void writeToBinary(ofstream& out, CPU& obj);				//Записывает объект obj в бинарный файл
	void readFromBinary(ifstream& in, CPU& obj);				//Читает объект obj из бинарного файла
};
