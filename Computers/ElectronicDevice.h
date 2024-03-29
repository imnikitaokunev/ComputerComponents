#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include "Input.h"
#include "InputNumber.cpp"
using namespace std;

enum Field
{
	COST,
	MODEL,
	CAPACITY,
	MEMORYTYPE,
	MEMORYSIZE,
	BASEFREQUENCY,
	COUNTOFCORES, 
	DRIVE
};

class ElectronicDevice
{
protected:
	string model;			//������ �������
	int cost;				//���������
	
public:
	static Field field;
	ElectronicDevice(string mdl = "", int cst = 0)
	{
		model = mdl;
		cost = cst;
	}
	~ElectronicDevice()
	{

	}
	ElectronicDevice(const ElectronicDevice& other)
	{
		this->model = other.model;
		this->cost = other.cost;
	}

	void setModel(string mdl);
	void setCost(int cst);
	string getModel() const;
	int getCost() const;

	virtual void title();												//��������� � ������ ������
	virtual void header();												//��������� �������

	friend istream& operator >>(istream& in, ElectronicDevice& obj);
	friend ostream& operator <<(ostream& out, ElectronicDevice& obj);
	friend ifstream& operator >>(ifstream& in, ElectronicDevice& obj);
	friend ofstream& operator <<(ofstream& out, ElectronicDevice& obj);
};
