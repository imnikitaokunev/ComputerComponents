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
	Memory(const Memory& other) : ElectronicDevice(other)
	{
		this->memoryType = other.memoryType;
		this->capacity = other.capacity;
	}
	void setMemoryType(string memtype);
	void setCapacity(int cap);
	string getMemoryType() const;
	int getCapacity() const;
	virtual void title();
	virtual void header();
	friend istream& operator >> (istream& in, Memory& obj);
	friend ostream& operator << (ostream& out, Memory& obj);
};