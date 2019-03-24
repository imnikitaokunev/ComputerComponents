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
	obj.countOfCores = inputNumber(MIN, MAXCORES);
	cout << "Базовая частота: ";
	obj.baseFrequency = inputNumber(MIN, MAXFREQUENCY);
	return in;
}

ostream& operator << (ostream& out, CPU& obj)
{
	out << dynamic_cast<ElectronicDevice&> (obj);
	out << setw(4) << "|" << setw(8) << obj.countOfCores << setw(4) << "|" << setw(8)
		<< obj.baseFrequency;
	return out;
}
