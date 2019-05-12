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
	cout << setw(38) << "---����������---" << endl;
}

void GraphicsCard::header()
{
	ElectronicDevice::header();
	cout << setw(4) << "|" << setw(7) << "VRAM" << endl;
	cout << setw(44) << "-----------|----------|---------" << endl;
}

void GraphicsCard::change()
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
			<< "\t3. ����� �����������." << endl
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
			cout << "����� ����� �����������: ";
			this->memorySize = inputNumber(MIN, MAXVRAM);
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

void GraphicsCard::search(bool* flag)
{
	GraphicsCard temp;
	char choice;

	do
	{
		system("cls");
		this->title();
		cout << endl;
		cout << "  �� ����� ����� �� ������� ��������� �����?" << endl;
		cout << "\t1. ������." << endl
			<< "\t2. ���������." << endl	
			<< "\t3. ����� �����������." << endl
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
			cout << "����� �����������: ";
			flag[MEMORYSIZE] = true;
			this->memorySize = inputNumber(MIN, MAXVRAM);
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

void GraphicsCard::changeField()
{
	char choice;

	system("cls");
	this->title();
	cout << endl;
	cout << "  �� ������ ���� ��������� ������?" << endl;
	cout << "\t1. ������." << endl
		<< "\t2. ���������." << endl	
		<< "\t3. ����� �����������." << endl
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
		field = MEMORYSIZE;
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

bool GraphicsCard::isEqual(GraphicsCard& other)
{
	if (field == COST)
		if (this->cost == other.cost)
			return true;
	if (field == MODEL)
		if (this->model == other.model)
			return true;
	if (field == MEMORYSIZE)
		if (this->memorySize == other.memorySize)
			return true;

	return false;
}

bool GraphicsCard::isEqual(GraphicsCard& other, bool* flag)
{
	if (flag[COST] == true)
		if (this->cost != other.cost)
			return false;
	if (flag[MODEL] == true)
		if (this->model != other.model)
			return false;	
	if (flag[MEMORYSIZE] == true)
		if (this->memorySize != other.memorySize)
			return false;

	return true;
}

bool GraphicsCard::operator==(GraphicsCard& other)
{
	if (this->cost != other.cost)
		return false;
	if (this->model != other.model)
		return false;
	if (this->memorySize != other.memorySize)
		return false;

	return true;
}

bool GraphicsCard::operator>(GraphicsCard& other)
{
	if (field == COST)
		if (this->cost > other.cost)
			return true;
	if (field == MODEL)
		if (this->model > other.model)
			return true;
	if (field == MEMORYSIZE)
		if (this->memorySize > other.memorySize)
			return true;

	return false;
}

bool GraphicsCard::operator<(GraphicsCard& other)
{
	if (field == COST)
		if (this->cost < other.cost)
			return true;
	if (field == MODEL)
		if (this->model < other.model)
			return true;
	if (field == MEMORYSIZE)
		if (this->memorySize < other.memorySize)
			return true;

	return false;
}

istream& operator >>(istream& in, GraphicsCard& obj)
{
	in >> dynamic_cast<ElectronicDevice&> (obj);
	cout << "����� �����������: ";
	obj.memorySize = inputNumber(MIN, MAXVRAM);
	return in;
}

ostream& operator << (ostream& out, GraphicsCard& obj)
{
	out << dynamic_cast<ElectronicDevice&> (obj);
	out << setw(4) << "|" << setw(7) << obj.memorySize;
	return out;
}

ifstream& operator >> (ifstream& fin, GraphicsCard& obj)
{
	fin >> dynamic_cast<ElectronicDevice&> (obj);
	fin >> obj.memorySize;
	fin.get();

	return fin;
}

ofstream& operator << (ofstream& fout, GraphicsCard& obj)
{
	fout << dynamic_cast<ElectronicDevice&> (obj);
	fout << ' ' << obj.memorySize;

	return fout;
}

void GraphicsCard::writeToBinary(ofstream& out, GraphicsCard& obj)
{
	size_t length = obj.model.length();
	out.write(reinterpret_cast<char*>(&length), sizeof(length));
	out.write(obj.model.c_str(), sizeof(obj.model));
	out.write(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	out.write(reinterpret_cast<char*>(&obj.memorySize), sizeof(obj.memorySize));
	out.write("\n", sizeof("\n"));
}

void GraphicsCard::readFromBinary(ifstream& in, GraphicsCard& obj)
{
	size_t length;
	in.read(reinterpret_cast<char*>(&length), sizeof(length));
	in.read(const_cast<char*>(obj.model.c_str()), sizeof(obj.model));
	in.read(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	in.read(reinterpret_cast<char*>(&obj.memorySize), sizeof(obj.memorySize));
	string buf;
	getline(in, buf, '\n');
	in.get();
}
