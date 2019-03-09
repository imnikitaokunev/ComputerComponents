#include "GraphicsCard.h"

void GraphicsCard::setMemorySize(int mem)
{
	memorySize = mem;
}

int GraphicsCard::getMemorySize() const
{
	return memorySize;
}

void GraphicsCard::title()
{
	cout << setw(38) << "---Graphics Card---" << endl;
}

void GraphicsCard::header()
{
	ElectronicDevice::header();
	cout << setw(4) << "|" << setw(7) << "VRAM" << endl;
	cout << setw(44) << "-----------|----------|---------" << endl;
}

istream& operator >>(istream& in, GraphicsCard& obj)
{
	in >> dynamic_cast<ElectronicDevice&> (obj);
	cout << "Видеопамять: ";
	in >> obj.memorySize;
	return in;
}

ostream& operator << (ostream& out, GraphicsCard& obj)
{
	out << dynamic_cast<ElectronicDevice&> (obj);
	out << setw(4) << "|" << setw(7) << obj.memorySize;
	return out;
}
