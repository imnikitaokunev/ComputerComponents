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
	cout << setw(67) << "---����������---" << endl;
}

void CPU::header()
{
	ElectronicDevice::header();
	cout << setw(4) << "|" << setw(8) << "Cores" << setw(4) << "|" << setw(8)
		<< "Freq." << endl;

	cout << setw(57) << "-----------|----------|-----------|----------" << endl;
}

void CPU::change()
{
	char choice;

	do
	{
		system("cls");
		this->title();
		cout << endl;
		cout << "  ����� ���� �� ������� ��������?" << endl;
		cout << "\t1. ������." << endl
			<< "\t2. ���������." << endl
			<< "\t3. ���������� ���� ����������." << endl
			<< "\t4. ������� ������� ����������." << endl
			<< "\t0. �����." << endl
			<< endl << "\t  >> ";
		choice = _getch();
		cout << choice << endl << endl;

		switch (choice)
		{
		case '1':
			cout << "����� ������: ";
			this->model = inputStringWithNums();
			break;
		case '2':
			cout << "����� ���������: ";
			this->cost = inputNumber(MIN, MAX);
			break;
		case '3':
			cout << "����� ���������� ���� ����������: ";
			this->countOfCores = inputNumber(MIN, MAXCORES);
			break;
		case '4':
			cout << "����� ������� ������� ���������: ";
			this->baseFrequency = inputNumber(MIN, MAXFREQUENCY);
			break;
		case '0':
			break;
		default:
			cout << endl;
			cout << "������������ ����." << endl;;
			system("pause");
			break;
		}
		cout << "������� ����� ������, ����� �������� ���-�� ���." << endl;
		cout << "���� �� ������ �� ������ ���-�� ��������, ������� 0:   ";
		choice = _getch();
		cout << choice << endl;

	} while (choice != '0');

}

void CPU::search(bool* flag)
{
	CPU temp;
	char choice;

	do
	{
		system("cls");
		this->title();
		cout << endl;
		cout << "  �� ����� ����� �� ������� ��������� �����?" << endl;
		cout << "\t1. ������." << endl
			<< "\t2. ���������." << endl
			<< "\t3. ���������� ���� ����������." << endl
			<< "\t4. ������� ������� ����������." << endl
			<< "\t0. �����." << endl
			<< endl << "\t  >> ";
		choice = _getch();
		cout << choice << endl << endl;

		switch (choice)
		{
		case '1':
			cout << "������: ";
			flag[MODEL] = true;
			this->model = inputStringWithNums();
			break;
		case '2':
			cout << "���������: ";
			flag[COST] = true;
			this->cost = inputNumber(MIN, MAX);
			break;
		case '3':
			cout << "���������� ���� ����������: ";
			flag[COUNTOFCORES] = true;
			this->countOfCores = inputNumber(MIN, MAXCORES);
			break;
		case '4':
			cout << "������� ������� ���������: ";
			flag[BASEFREQUENCY] = true;
			this->baseFrequency = inputNumber(MIN, MAXFREQUENCY);
			break;
		case '0':
			break;
		default:
			cout << endl;
			cout << "������������ ����." << endl;;
			system("pause");
			break;
		}
		cout << "������� ����� ������, ����� �������� ���-�� ���." << endl;
		cout << "���� �� �� ������ �������� ���-�� ���, ������� 0:   ";
		choice = _getch();
		cout << choice << endl;

	} while (choice != '0');

}

void CPU::changeField()
{
	char choice;

	system("cls");
	this->title();
	cout << endl;
	cout << "  �� ������ ���� ��������� ������?" << endl;
	cout << "\t1. ������." << endl
		<< "\t2. ���������." << endl
		<< "\t3. ���������� ���� ����������." << endl
		<< "\t4. ������� ������� ����������." << endl
		<< "\t0. �����." << endl
		<< endl << "\t  >> ";
	choice = _getch();
	cout << choice << endl << endl;

	switch (choice)
	{
	case '1':
		field = MODEL;
		break;
	case '2':
		field = COST;
		break;
	case '3':
		field = COUNTOFCORES;
		break;
	case '4':
		field = BASEFREQUENCY;
		break;
	case '0':
		break;
	default:
		cout << endl;
		cout << "������������ ����." << endl;;
		system("pause");
		break;
	}
}

bool CPU::isEqual(CPU& other)
{
	if (field == COST)
		if (this->cost == other.cost)
			return true;
	if (field == MODEL)
		if (this->model == other.model)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency == other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores == other.countOfCores)
			return true;

	return false;
}

bool CPU::isEqual(CPU& other, bool* flag)
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

bool CPU::operator==(CPU& other)
{
	if (this->cost != other.cost)
		return false;
	if (this->model != other.model)
		return false;
	if (this->baseFrequency != other.baseFrequency)
		return false;
	if (this->countOfCores != other.countOfCores)
		return false;

	return true;
}

bool CPU::operator>(CPU& other)
{
	if (field == COST)
		if (this->cost > other.cost)
			return true;
	if (field == MODEL)
		if (this->model > other.model)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency > other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores > other.countOfCores)
			return true;

	return false;
}

bool CPU::operator<(CPU& other)
{
	if (field == COST)
		if (this->cost < other.cost)
			return true;
	if (field == MODEL)
		if (this->model < other.model)
			return true;
	if (field == BASEFREQUENCY)
		if (this->baseFrequency < other.baseFrequency)
			return true;
	if (field == COUNTOFCORES)
		if (this->countOfCores < other.countOfCores)
			return true;

	return false;
}

istream& operator >> (istream& in, CPU& obj)
{
	in >> dynamic_cast<ElectronicDevice&> (obj);
	cout << "���������� ����: ";
	obj.countOfCores = inputNumber(MIN, MAXCORES);
	cout << "������� �������: ";
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

ifstream& operator >> (ifstream& fin, CPU& obj)
{
	fin >> dynamic_cast<ElectronicDevice&> (obj);
	fin >> obj.countOfCores;
	fin >> obj.baseFrequency;
	fin.get();

	return fin;
}

ofstream& operator << (ofstream& fout, CPU& obj)
{
	fout << dynamic_cast<ElectronicDevice&> (obj);
	fout << ' ' << obj.countOfCores << ' ' << obj.baseFrequency;

	return fout;
}

void CPU::writeToBinary(ofstream& out, CPU& obj)
{
	out.write(obj.model.c_str(), sizeof(obj.model));
	out.write(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	out.write(reinterpret_cast<char*>(&obj.countOfCores), sizeof(obj.countOfCores));
	out.write(reinterpret_cast<char*>(&obj.baseFrequency), sizeof(obj.baseFrequency));
	out.write("\n", sizeof("\n"));
}

void CPU::readFromBinary(ifstream& in, CPU& obj)
{
	in.read(const_cast<char*>(obj.model.c_str()), sizeof(obj.model));
	in.read(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	in.read(reinterpret_cast<char*>(&obj.countOfCores), sizeof(obj.countOfCores));
	in.read(reinterpret_cast<char*>(&obj.baseFrequency), sizeof(obj.baseFrequency));
	string buf;
	getline(in, buf, '\n');
	in.get();
}
