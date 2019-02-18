#include "ElectronicDevice.h"

void ElectronicDevice::setModel(string mdl)
{
	model = mdl;
}

void ElectronicDevice::setCost(int cst)
{
	cost = cst;
}

string ElectronicDevice::getModel() const
{
	return model;
}

int ElectronicDevice::getCost() const
{
	return cost;
}

void ElectronicDevice::header()
{
	cout << setw(20) << "Model" << setw(4) << "|" << setw(7) << "Cost";
}

void ElectronicDevice::title()
{
	cout << endl << setw(73) << "---Electronic appliancies---" << endl;
}

istream& operator >>(istream& in, ElectronicDevice& obj)
{
	cout << "Model: ";
	in >> obj.model;
	cout << "Cost: ";
	in >> obj.cost;
	return in;
}

ostream& operator << (ostream& out, ElectronicDevice& obj)
{
	out << setw(20) << obj.model << setw(4) << "|" << setw(7) << obj.cost;
	return out;
}