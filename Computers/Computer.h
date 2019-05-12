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
	virtual void title() override;
	virtual void header() override;

	void change();
	void search(bool *flag);
	void changeField();

	bool isEqual(Computer& other);
	bool isEqual(Computer& other, bool* flag);
	bool operator == (Computer& other);
	bool operator >(Computer& other);
	bool operator <(Computer& other);
	friend istream& operator >> (istream& in, Computer& obj);
	friend ostream& operator << (ostream& out, Computer& obj);
	friend ifstream& operator >> (ifstream& fin, Computer& obj);
	friend ofstream& operator << (ofstream& fout, Computer& obj);
	void writeToBinary(ofstream& fout, Computer& obj);
	void readFromBinary(ifstream& fin, Computer& obj);
};