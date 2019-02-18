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
	CPU(const CPU& other)
	{
		this->countOfCores = other.countOfCores;
		this->baseFrequency = other.baseFrequency;
	}
	void setCountOfCores(int cores);
	void setBaseFrequency(int freq);
	int getCountOfCores() const;
	int getBaseFrequency() const;
	virtual void title() override;
	virtual void header() override;
	friend istream& operator >> (istream& in, CPU& obj);
	friend ostream& operator << (ostream& out, CPU& obj);

};
