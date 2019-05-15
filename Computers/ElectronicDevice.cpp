#include "ElectronicDevice.h"

Field ElectronicDevice::field = MODEL;

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
	cout << endl << setw(73) << "---Электронные устройства---" << endl << endl;
}

istream& operator >>(istream& in, ElectronicDevice& obj)
{
	do {
		try {
			cout << "Модель: ";
			obj.model = inputStringWithNums();
		}
		catch (const char* str)
		{
			cout << str << endl;
		}
	} while (obj.model == "");
	cout << "Стоимость: ";
	obj.cost = inputNumber(MIN, MAX);
	return in;
}

ostream& operator << (ostream& out, ElectronicDevice& obj)
{
	out << setw(20) << obj.model << setw(4) << "|" << setw(7) << obj.cost;
	return out;
}

ifstream& operator >>(ifstream& fin, ElectronicDevice& obj)
{
	getline(fin, obj.model, '*');
	fin >> obj.cost;

	return fin;
}

ofstream& operator <<(ofstream& fout, ElectronicDevice& obj)
{
	fout << obj.model << "*" << ' ' << obj.cost;

	return fout;
}
