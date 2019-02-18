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
		this->memorySize = other.memorySize;
	}
	void setMemorySize(int mem);
	int getMemorySize() const;
	virtual void title() override;
	virtual void header() override;
	friend istream& operator >> (istream& in, GraphicsCard& obj);
	friend ostream& operator << (ostream& out, GraphicsCard& obj);
};