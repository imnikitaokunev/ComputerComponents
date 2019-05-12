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
	virtual void title() override;
	virtual void header() override;

	void change();
	void search(bool* flag);
	void changeField();

	bool isEqual(Memory& other);
	bool isEqual(Memory& other, bool* flag);
	bool operator == (Memory& other);
	bool operator >(Memory& other);
	bool operator <(Memory& other);
	friend istream& operator >> (istream& in, Memory& obj);
	friend ostream& operator << (ostream& out, Memory& obj);
	friend ifstream& operator >> (ifstream& fin, Memory& obj);
	friend ofstream& operator << (ofstream& fout, Memory& obj);
	void writeToBinary(ofstream& out, Memory& obj);
	void readFromBinary(ifstream& in, Memory& obj);
};