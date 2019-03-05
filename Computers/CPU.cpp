#include "CPU.h"

void CPU::setCountOfCores(int cores)
{
	countOfCores = cores;
}

void CPU::setBaseFrequency(int freq)
{
	baseFrequency = freq;
}

int CPU::getCountOfCores() const
{
	return countOfCores;
}

int CPU::getBaseFrequency() const
{
	return baseFrequency;
}

void CPU::title()
{
	cout << setw(39) << "---Процессоры---" << endl;
}

void CPU::header()
{
	ElectronicDevice::header();
	cout << setw(4) << "|" << setw(8) << "Cores" << setw(4) << "|" << setw(8)
		<< "Freq." << endl;

	cout << setw(57) << "-----------|----------|-----------|----------" << endl;
}

istream& operator >> (istream& in, CPU& obj)
{
	in >> dynamic_cast<ElectronicDevice&> (obj);
	cout << "Количество ядер: ";
	in >> obj.countOfCores;
	cout << "Базовая частота: ";
	in >> obj.baseFrequency;
	return in;
}

ostream& operator << (ostream& out, CPU& obj)
{
	out << dynamic_cast<ElectronicDevice&> (obj);
	out << setw(4) << "|" << setw(8) << obj.countOfCores << setw(4) << "|" << setw(8)
		<< obj.baseFrequency;
	return out;
}

bool CPU::compare(CPU& other, bool* flag)
{
	if (flag[COST] == true)
		if (this->cost != other.cost)
			return false;
	if (flag[MODEL] == true)
		if (this->model != other.model)
			return false;
	if (flag[BASEFREQUENCY] == true)
		if (this->baseFrequency != other.baseFrequency)
			return false;
	if (flag[COUNTOFCORES] == true)
		if (this->countOfCores != other.countOfCores)
			return false;

	return true;
}
