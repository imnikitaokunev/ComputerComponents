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
	cout << setw(64) << "---����������� ������---" << endl;
}

void Memory::header()
{
	ElectronicDevice::header();
	cout << setw(4) << "|" << setw(6) << "RAM" << setw(4) << "|" <<
		setw(11) << "Capacity" << endl;
	cout << setw(59) << "-----------|----------|---------|--------------" << endl;
}

void Memory::change()
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
			<< "\t3. ��� ���." << endl
			<< "\t4. ����� ���." << endl
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
			cout << "����� ��� ���: ";
			this->memoryType = inputStringWithNums();
			break;
		case '4':
			cout << "����� ����� ���: ";
			this->capacity = inputNumber(MIN, MAXCAPACITY);
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

void Memory::search(bool* flag)
{
	Memory temp;
	char choice;

	do
	{
		system("cls");
		this->title();
		cout << endl;
		cout << "  �� ����� ����� �� ������� ��������� �����?" << endl;
		cout << "\t1. ������." << endl
			<< "\t2. ���������." << endl
			<< "\t3. ��� ���." << endl
			<< "\t4. ����� ���." << endl
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
			cout << "��� ���: ";
			flag[MEMORYTYPE] = true;
			this->memoryType = inputStringWithNums();
			break;
		case '4':
			cout << "����� ���: ";
			flag[CAPACITY] = true;
			this->capacity = inputNumber(MIN, MAXCAPACITY);
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

void Memory::changeField()
{
	char choice;

	system("cls");
	this->title();
	cout << endl;
	cout << "  �� ������ ���� ��������� ������?" << endl;
	cout << "\t1. ������." << endl
		<< "\t2. ���������." << endl
		<< "\t3. ��� ���." << endl
		<< "\t4. ����� ���." << endl
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
		field = MEMORYTYPE;
		break;
	case '4':
		field = CAPACITY;
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

bool Memory::isEqual(Memory& other)
{
	if (field == COST)
		if (this->cost == other.cost)
			return true;
	if (field == MODEL)
		if (this->model == other.model)
			return true;
	if (field == CAPACITY)
		if (this->capacity == other.capacity)
			return true;
	if (field == MEMORYTYPE)
		if (this->memoryType == other.memoryType)
			return true;

	return false;
}

bool Memory::isEqual(Memory& other, bool* flag)
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

bool Memory::operator==(Memory& other)
{
	if (this->cost != other.cost)
		return false;
	if (this->model != other.model)
		return false;
	if (this->capacity != other.capacity)
		return false;
	if (this->memoryType != other.memoryType)
		return false;

	return true;
}

bool Memory::operator>(Memory& other)
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

	return false;
}

bool Memory::operator<(Memory& other)
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

	return false;
}

istream& operator >> (istream& in, Memory& obj)
{
	in >> dynamic_cast<ElectronicDevice&> (obj);
	cout << "��� ���: ";
	obj.memoryType = inputStringWithNums();
	cout << "������� ���: ";
	obj.capacity = inputNumber(MIN, MAXCAPACITY);
	return in;
}

ostream& operator << (ostream& out, Memory& obj)
{
	out << dynamic_cast<ElectronicDevice&> (obj);
	out << setw(4) << "|" << setw(6) << obj.memoryType << setw(4) << "|" <<
		setw(11) << obj.capacity;
	return out;
}

ifstream& operator >> (ifstream& fin, Memory& obj)
{
	fin >> dynamic_cast<ElectronicDevice&>(obj);
	fin.get();
	getline(fin, obj.memoryType, '*');	
	fin >> obj.capacity;
	fin.get();

	return fin;
}

ofstream& operator << (ofstream& fout, Memory& obj)
{
	fout << dynamic_cast<ElectronicDevice&> (obj);
	fout << ' ' << obj.memoryType << '*' << ' ' << obj.capacity;

	return fout;
}

void Memory::writeToBinary(ofstream& out, Memory& obj)
{
	out.write(obj.model.c_str(), sizeof(obj.model));
	out.write(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	out.write(obj.memoryType.c_str(), sizeof(obj.memoryType));
	out.write(reinterpret_cast<char*>(&obj.capacity), sizeof(obj.capacity));
	out.write("\n", sizeof("\n"));
}

void Memory::readFromBinary(ifstream& in, Memory& obj)
{
	in.read(const_cast<char*>(obj.model.c_str()), sizeof(obj.model));
	in.read(reinterpret_cast<char*>(&obj.cost), sizeof(obj.cost));
	in.read(const_cast<char*>(obj.memoryType.c_str()), sizeof(obj.memoryType));
	in.read(reinterpret_cast<char*>(&obj.capacity), sizeof(obj.capacity));
	string buf;
	getline(in, buf, '\n');
	in.get();
}
