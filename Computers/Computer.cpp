#include "Computer.h"



void Computer::setDrive(int dr)
{
	drive = dr;
}

int Computer::getDrive() const
{
	return drive;
}

void Computer::title()
{
	cout << setw(67) << "---Компьютеры---" << endl;
}

void Computer::header()
{
	ElectronicDevice::header();
	cout << setw(4) << "|" << setw(8) << "Cores" << setw(4) << "|" << setw(8)
		<< "Freq." << setw(4) << "|" << setw(7) << "VRAM" << setw(4) << "|" 
		<< setw(6) << "RAM" << setw(4) << "|" << setw(11) << "Capacity" << setw(4)
		<< "|" << setw(8) << "Drive" << endl;
	cout << setw(105) << "----------|----------|-----------|-----------|----------|---------|--------------|----------" << endl;
}

istream& operator >>(istream& in, Computer& obj)
{
	in >> dynamic_cast<CPU&> (obj);
	cout << "Видеопамять: ";
	in >> obj.memorySize;
	cout << "Тип ОЗУ: ";
	in >> obj.memoryType;
	cout << "Емкость ОЗУ: ";
	in >> obj.capacity;
	cout << "Винчестер: ";
	in >> obj.drive;
	return in;
}

ostream& operator <<(ostream& out, Computer& obj)
{
	out << dynamic_cast <CPU&> (obj);
	out << setw(4) << "|" << setw(7) << obj.memorySize << setw(4) << "|" << setw(6)
		<< obj.memoryType << setw(4) << "|" << setw(11) << obj.capacity << setw(4)
		<< "|" << setw(8) << obj.drive;
	return out;
}


bool Computer::operator==(Computer& other)
{
	if (field == COST)
		if (this->cost != other.cost)
			return false;
	if (field == MODEL)
		if (this->model != other.model)
			return false;
	if (field == CAPACITY)
		if (this->capacity != other.capacity)
			return false;
	if (field == MEMORYTYPE)
		if (this->memoryType != other.memoryType)
			return false;
	if (field == MEMORYSIZE)
		if (this->memorySize != other.memorySize)
			return false;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency != other.baseFrequency)
			return false;
	if (field == COUNTOFCORES)
		if (this->countOfCores != other.countOfCores)
			return false;
	if (field == DRIVE)
		if (this->drive != other.drive)
			return false;

	return true;
}

bool Computer::operator<(Computer& other)
{
	if (field == COST)
		if (this->cost < other.cost)
			return true;
	if (field == MODEL)
		if (this->model < other.model)
			return true;
	if (field == CAPACITY)
		if (this->capacity < other.capacity)
			return true;
	if (field == MEMORYTYPE)
		if (this->memoryType < other.memoryType)
			return true;
	if (field == MEMORYSIZE)
		if (this->memorySize < other.memorySize)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency < other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores < other.countOfCores)
			return true;
	if (field == DRIVE)
		if (this->drive < other.drive)
			return true;

	return false;
}

bool Computer::operator>(Computer& other)
{
	if (field == COST)
		if (this->cost > other.cost)
			return true;
	if (field == MODEL)
		if (this->model > other.model)
			return true;
	if (field == CAPACITY)
		if (this->capacity > other.capacity)
			return true;
	if (field == MEMORYTYPE)
		if (this->memoryType > other.memoryType)
			return true;
	if (field == MEMORYSIZE)
		if (this->memorySize > other.memorySize)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency > other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores > other.countOfCores)
			return true;
	if (field == DRIVE)
		if (this->drive > other.drive)
			return true;

	return false;
}

bool Computer::isEqual(Computer& other, bool *flag)
{
	if (flag[COST] == true)
		if (this->cost != other.cost)
			return false;
	if (flag[MODEL] == true)
		if (this->model != other.model)
			return false;
	if (flag[CAPACITY] == true)
		if (this->capacity != other.capacity)
			return false;
	if (flag[MEMORYTYPE] == true)
		if (this->memoryType != other.memoryType)
			return false;
	if (flag[MEMORYSIZE] == true)
		if (this->memorySize != other.memorySize)
			return false;
	if (flag[BASEFREQUENCY] == true)
		if (this->baseFrequency != other.baseFrequency)
			return false;
	if (flag[COUNTOFCORES] == true)
		if (this->countOfCores != other.countOfCores)
			return false;
	if (flag[DRIVE] == true)
		if (this->drive != other.drive)
			return false;

	return true;
}
