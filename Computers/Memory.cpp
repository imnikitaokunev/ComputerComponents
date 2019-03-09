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
	cout << "Òèï ÎÇÓ: ";
	obj.memoryType = inputString();
	cout << "Åìêîñòü ÎÇÓ: ";
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
