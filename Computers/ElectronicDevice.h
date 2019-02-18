#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class ElectronicDevice
{
protected:
	string model;		//Модель прибора
	int cost;			//Стоимость

public:
	ElectronicDevice(string mdl = "", int cst = 0)
	{
		model = mdl;
		cost = cst;
	}
	~ElectronicDevice()
	{

	}
	ElectronicDevice(const ElectronicDevice& obj)
	{
		this->model = obj.model;
		this->cost = obj.cost;
	}

	void setModel(string mdl);
	void setCost(int cst);
	string getModel() const;
	int getCost() const;
	virtual void title();
	virtual void header();

	friend istream& operator >>(istream& in, ElectronicDevice& obj);
	friend ostream& operator <<(ostream& out, ElectronicDevice& obj);
};

