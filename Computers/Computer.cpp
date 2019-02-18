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
	cout << setw(67) << "---Computers---" << endl;
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
	cout << "VRAM: ";
	in >> obj.memorySize;
	cout << "RAM type: ";
	in >> obj.memoryType;
	cout << "Capacity: ";
	in >> obj.capacity;
	cout << "Drive: ";
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
