#include "Memory.h"

void Memory::setMemoryType(string memtype)
{
	memoryType = memtype;
}

void Memory::setCapacity(int cap)
{
	capacity = cap;
}

string Memory::getMemoryType() const
{
	return memoryType;
}

int Memory::getCapacity() const
{
	return capacity;
}

void Memory::title()
{
	cout << setw(41) << "---Memory---" << endl;
}

void Memory::header()
{
	ElectronicDevice::header();
	cout << setw(4) << "|" << setw(6) << "RAM" << setw(4) << "|" <<
		setw(11) << "Capacity" << endl;
	cout << setw(59) << "-----------|----------|---------|--------------" << endl;
}

istream& operator >> (istream& in, Memory& obj)
{
	in >> dynamic_cast<ElectronicDevice&> (obj);
	cout << "RAM type: ";
	in >> obj.memoryType;
	cout << "Capacity: ";
	in >> obj.capacity;
	return in;
}

ostream& operator << (ostream& out, Memory& obj)
{
	out << dynamic_cast<ElectronicDevice&> (obj);
	cout << setw(4) << "|" << setw(6) << obj.memoryType << setw(4) << "|" <<
		setw(11) << obj.capacity;
	return out;
}

bool Memory::compare(Memory& other, bool* flag)
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

	return true;
}